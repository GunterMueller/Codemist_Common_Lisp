
/*
 Copyright (c) 1991-2002, The Numerical Algorithms Group Ltd.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are
 met:
 
     - Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
 
     - Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in
       the documentation and/or other materials provided with the
       distribution.
 
     - Neither the name of The Numerical ALgorithms Group Ltd. nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES-- LOSS OF USE, DATA, OR
 PROFITS-- OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <windows.h>   // required for all Windows applications
#include <setjmp.h>

/*
 * Changes:
 */

#include "csl.h"
#include "resource.h"  // Windows resource IDs
#include "AOExport.h"
#include "axfns.h"
#include "buf.h"
#include "axiom.h"

/*
 * Debugging
 */
/*#define DEBUG*/
#ifdef DEBUG
#define axDEBUG(x) x
#else
#define axDEBUG(x)
#endif

/*#define AXIOM_DEBUG*/
#ifdef AXIOM_DEBUG
#include <stdio.h>
int msg, fref;
FILE *file;
#define DebugOpenFile() (fref == 0 ? (file = fopen("/foo.out", "a"), fref++): fref ++)
#define DebugCloseFile() (fref--, fref == 0 ? (fclose(file), file = NULL,0): 1)
#define DebugPrint(s, arg) fprintf(file, "CCL: %d: " s, msg++, arg);
#else
#define DebugOpenFile()
#define DebugCloseFile()
#define DebugPrint(s, arg)
#endif


/*
 * This program.
 */
char szAppName[] = "Axiom";   // The name of this application
char szTitle[]   = "Axiom Application"; // The title bar text
char axFunc[256] = "call-saturn";

/*
 *
 * Resources 
 */

/*
 * My own messages
 */
#define WM_DoAxiomCall	      (WM_USER + 1)

static char *axCclArgs[]  = { 
	"ccl.exe", 
	"-I", "saturn.img", 
	"-I", "axiom.lib",
	"-I", "axiomaut.lib",
	"-I", "axiomw32.lib"
};

#define   axCclNArgs  9

#define axArgsLibStart 2
#define axArgsNImages  4

static BOOL  axBeNoisy = FALSE;
static HWND  axOutControl = NULL;
static HWND  axInControl = NULL;
static HWND  axMainWnd;
static int   axInterrupted = FALSE;
static Buffer axLineOutput;
static void  *axOutputHandle = NULL;
static Buffer axInputBuffer;

static AxiomCall axThisCall; 

typedef struct {
  int	  error;
  char   *msg;
  jmp_buf  buf;
} AxRestoreContext;

static AxRestoreContext axContext;
typedef enum { RS_Init, RS_Idle, RS_Exec, RS_Input, RS_Exit } AxRunState;
static AxRunState axRunningState; 

/* 
 * Globals 
 */
static HINSTANCE hInst;          // current instance
static HANDLE hAccelTable;

static BOOL             axInitApplication	(HANDLE);
static BOOL             axInitInstance		(HANDLE, int, LPSTR);
static void		axMakeInternalWindows	(HWND, LPCREATESTRUCT);
static void		axResizeInternalWindows	(int, int);
static LRESULT CALLBACK axMainWndProc		( HWND, UINT, WPARAM, LPARAM);
static LRESULT CALLBACK axAbout  		(HWND, UINT, WPARAM, LPARAM);
static void		axDoCall	(WPARAM, LONG);
static void		axDoCall0	(AxiomCall);
static void             axTidyUp 	(void);
       void             axWrString 	(const char *, BOOL);
static void		axUpdateOutput  (char *);
static int              axWrite 	(int);
static void             axFlushOutput 	(void);
static int              axRead 		(void);
static void             axDoInput       (int);
static BOOL		axStartCcl	(LPSTR);
static BOOL		axInitialiseEnv	();
static void		axDoCclInitFailure (void);
static char *		axGetRegistryEnvItem(char *s);
static short AxHandleType axCommandHandler( AxiomCall );
static void  		axGetInput	(Buffer buf);
static void		axSwitchMenus	(AxRunState);

/* Command list functions */
static BOOL		axCmdEmpty	(void);
static AxiomCall	axCmdGetNext	(void);
static void		axCmdAdd	(AxiomCall);
static void		axCmdKillQueue  ();
CRITICAL_SECTION	axCmdSem;

/* Registry functions ... */
static HKEY		rgGetSoftwareKey (void);
static HKEY		rgGetSubKey	 (HKEY, const char *, 
					  const char *);

/* Normalising calls */
static char *		axNormalizeCall	 (AxiomCall);
static void		axCleanupCall	 (char *);

/****************************************************************************

FUNCTION: WinMain(HINSTANCE, HINSTANCE, LPSTR, int)

PURPOSE: calls initialization function, processes message loop

COMMENTS:

        Windows recognizes this function by name as the initial entry point
        for the program.  This function calls the application initialization
        routine, if no other instance of the program is running, and always
        calls the instance initialization routine.  It then executes a message
        retrieval and dispatch loop that is the top-level control structure
        for the remainder of execution.  The loop is terminated when a WM_QUIT
        message is received, at which time this function exits the application
        instance by returning the value passed by PostQuitMessage().

        If this function must abort before entering the message loop, it
        returns the conventional value NULL.

****************************************************************************/


int CALLBACK 
WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg;

    if (!hPrevInstance) {       // Other instances of app running?
        if (!axInitApplication(hInstance)) { // Initialize shared things
            return (FALSE);     // Exits if unable to initialize
        }
    }

    if (strstr(lpCmdLine, "mbedding") != NULL)
      nCmdShow = SW_SHOWMINNOACTIVE;
    else
      nCmdShow = SW_SHOW;

    /* Perform initializations that apply to a specific instance */

    InitializeCriticalSection(&axCmdSem);

    axDEBUG(file = fopen("/tmp/foo.out", "w"));

    if (!axInitInstance(hInstance, nCmdShow, lpCmdLine)) {
        return (FALSE);
    }

    hAccelTable = LoadAccelerators (hInstance, MAKEINTRESOURCE(IDR_AXIOM));

    /* Acquire and dispatch messages until a WM_QUIT message is received. */

    while (GetMessage(&msg, // message structure
       NULL,   // handle of window receiving the message
       0,      // lowest message to examine
       0))     // highest message to examine
    {
        if (!TranslateAccelerator (msg.hwnd, hAccelTable, &msg)) {
            TranslateMessage(&msg);// Translates virtual key codes
            DispatchMessage(&msg); // Dispatches message to window
        }
    }

    axTidyUp();
    return (msg.wParam); // Returns the value from PostQuitMessage
}


/****************************************************************************

FUNCTION: axInitApplication(HINSTANCE)

PURPOSE: Initializes window data and registers window class

COMMENTS:

        This function is called at initialization time only if no other
        instances of the application are running.  This function performs
        initialization tasks that can be done once for any number of running
        instances.

        In this case, we initialize a window class by filling out a data
        structure of type WNDCLASS and calling the Windows RegisterClass()
        function.  Since all instances of this application use the same window
        class, we only need to do this when the first instance is initialized.


****************************************************************************/

BOOL 
axInitApplication(HINSTANCE hInstance)
{
    WNDCLASS  wc;

    // Fill in window class structure with parameters that describe the
    // main window.

    wc.style         = CS_HREDRAW | CS_VREDRAW;// Class style(s).
    wc.lpfnWndProc   = (WNDPROC)axMainWndProc;       // Window Procedure
    wc.cbClsExtra    = 0;                      // No per-class extra data.
    wc.cbWndExtra    = 0;                      // No per-window extra data.
    wc.hInstance     = hInstance;              // Owner of this class
    wc.hIcon         = LoadIcon (hInstance, MAKEINTRESOURCE(IDI_APP)); // Icon name from .RC
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);// Cursor
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);// Default color
    wc.lpszMenuName  = MAKEINTRESOURCE(IDR_AXIOM); // Menu from .RC
    wc.lpszClassName = szAppName;              // Name to register as

    // Register the window class and return success/failure code.
    return (RegisterClass(&wc));
}


/****************************************************************************

FUNCTION:  axInitInstance(HINSTANCE, int)

PURPOSE:  Saves instance handle and creates main window

COMMENTS:

        This function is called at initialization time for every instance of
        this application.  This function performs initialization tasks that
        cannot be shared by multiple instances.

        In this case, we save the instance handle in a static variable and
        create and display the main program window.

****************************************************************************/

BOOL 
axInitInstance( HINSTANCE hInstance, int nCmdShow, LPSTR lpCmdLine )
{
    HWND            hWnd; // Main window handle.
    char *str;
    // Save the instance handle in static variable, which will be used in
    // many subsequence calls from this application to Windows.

    hInst = hInstance; // Store instance handle in our global variable

    // Create a main window for this application instance.

    hWnd = CreateWindow(
            szAppName,           // See RegisterClass() call.
            szTitle,             // Text for window title bar.
            WS_OVERLAPPEDWINDOW,// Window style.
            CW_USEDEFAULT, CW_USEDEFAULT, 
	    300, 300, 		 // Use default positioning
            NULL,                // Overlapped windows have no parent.
            NULL,                // Use the window class menu.
            hInstance,           // This instance owns this window.
            NULL                 // We don't use any data in our WM_CREATE
    );

    // If window could not be created, return "failure"
    if (!hWnd) {
            return (FALSE);
    }

    str = getenv("CCLAXIOM_NOISE");
    if (str) axBeNoisy = TRUE;
    str = getenv("CCLAXIOM_FUNC");
    if (str) strcpy(axFunc, str);
    // !! AXIOM 

    // CCL
    axContext.error = 0;

    if (setjmp(axContext.buf) == 0) {
      if (!axStartCcl(lpCmdLine))
	return FALSE;
    }
    else {
      axDoCclInitFailure();
      return FALSE;
    }

axDEBUG(fprintf(file, "Done ccl\n"));
axDEBUG(fprintf(file, "Starting DLL\n"));
    // !! AXIOM 
    if (!InitializeAxiomOleDll( &axCommandHandler )) {
	    MessageBox(NULL, "Aborting...", "Axiom", MB_OK);
	    return FALSE;
    }
axDEBUG(fprintf(file, "Done dll\n"));
    // Make the window visible; update its client area; and return "success"

    ShowWindow(hWnd, nCmdShow); // Show the window
    UpdateWindow(hWnd);         // Sends WM_PAINT message

axDEBUG(fprintf(file, "Bingo\n"));
    return (TRUE);              // We succeeded...
}

static void
axTidyUp()
{
axDEBUG(fprintf(file, "Going home\n"));
axDEBUG(fclose(file));
	DeleteCriticalSection(&axCmdSem);
  	ExitAxiomDLL();
  	cslfinish(axWrite);
}


void
axWrString(const char *str, BOOL nl)
{
  while (*str != '\0') 
    axWrite((int)*(str++));
  if (nl)
    axWrite('\n');
}

static int
axWrite(int c)
{
	if (axLineOutput == NULL)
	  axLineOutput = bufNew(0, NULL);

	if (c == '\t')
	  bufAddTab(axLineOutput);
	else if (c == '\n') {
	  bufAddChar(axLineOutput, '\r');
	  bufAddChar(axLineOutput, (char) c);
	}
        else 
	  bufAddChar(axLineOutput,  (char) c);

	if (c == '\n') 
	  axFlushOutput();

	return 0;
}

static void
axFlushOutput()
{
  bufAddChar(axLineOutput, '\0');
  if (axOutputHandle) {
    OutputTextToAxiom(axOutputHandle, 
		      bufContents(axLineOutput));
  }
  if (axOutControl) {
    axUpdateOutput(bufContents(axLineOutput));
    bufReset(axLineOutput);
  }
}

static int
axRead(void)
{
  int c;
  static Buffer myBuf;

  if (axRunningState == RS_Exit) return EOF;

  if (axInputBuffer == NULL)
    axInputBuffer = bufNew(0, axGetInput); 

  c = bufGetc(axInputBuffer);

  if (!myBuf)
    myBuf = bufNew(0, NULL);

  bufAddChar(myBuf, (char) c);
  axWrite(c);
  return c;
}

static void
axGetInput(Buffer buf)
{
  // NB: This is truly disgusting
  // (below is a modal loop that commandeers 
  //  all 'DoInput' commands, and ignores the rest...)
  char title[50];
  int  tlen;
  MSG msg;

  axRunningState = RS_Input;
  axFlushOutput();
  tlen = GetWindowText(axMainWnd, title, 50);
  strcat(title, "(lisp input)");
  SetWindowText(axMainWnd, title);
  title[tlen] = '\0';

  while (GetMessage(&msg, 	// message structure
		    axMainWnd,	// handle of window receiving the message
		    0,  // lowest message to examine
		    0))     	// highest message to examine
    {
      BOOL snarf = FALSE;
      if (!TranslateAccelerator (msg.hwnd, hAccelTable, &msg)) {
	TranslateMessage(&msg);// Translates virtual key codes
	if (msg.message == WM_COMMAND) {
	  switch (LOWORD(msg.wParam)) {
	  case IDM_DoInputAsSpad:
	  case IDM_DoInputAsLisp:
	  case IDM_DoInputAsBoot:
	    snarf = TRUE;
	    break;

	  default:
	    break;
	  }
        }
	if (!snarf) 
	  DispatchMessage(&msg); // Dispatches message to window
	else {
	  char *chars;
	  char x[90];
	  int n = GetWindowTextLength(axInControl);
	  chars = (char *) malloc(n+1);
	  n = GetWindowText(axInControl, chars, n+1);
	  sprintf(x, "%d: '%s'", n, chars);
	  MessageBox(NULL,  "Msg", x, MB_OK);
	  SetWindowText(axInControl, "");
	  bufAddStr(buf, n, chars);
	  bufAddChar(buf, '\n');
	  SetWindowText(axMainWnd, title);
	  free(chars);
	  axRunningState = RS_Exec;
	  return;
	}
      }
    }
}

static int axNChars;

static void
axUpdateOutput(char *str)
{
  int tlen;
  axNChars+= strlen(str);
  
  /* We let the size increase to 20K, and then
   * cut down to 16K (this way we minimize the
   * playing around with the output box
   */
  if (axNChars > 20480) {
    char buf[100];
    while (axNChars > 16384) {
      int i = 0;
      char c;
      GetWindowText(axOutControl, buf, 100);
      while (i< 100) {
	c = buf[i++];
	if (c == 10 ||  c == '\0')
	  break;
      }
      if (c == 10) buf[i] = '\0';
      SendMessage(axOutControl, EM_SETSEL, 0, i);
      SendMessage(axOutControl, EM_REPLACESEL, 0, (LPARAM) "");
      axNChars -= i;
    }
    sprintf(buf, "%d", axNChars);
  }
  tlen = GetWindowTextLength(axOutControl);
  SendMessage(axOutControl, EM_SETSEL, tlen , tlen);

  SendMessage(axOutControl, EM_REPLACESEL,
	      0, (LPARAM) str);
}

extern "C" void
axFatalError(char *msg)
{
  axContext.msg = msg;
  longjmp(axContext.buf,1);
}

static void
axDoCclInitFailure()
{
  MessageBox(NULL, 
	     axLineOutput ? bufContents(axLineOutput): axContext.msg, 
	     "Axiom Initialisation Error", MB_OK);
}

/****************************************************************************

FUNCTION: axMainWndProc(HWND, UINT, WPARAM, LPARAM)

PURPOSE:  Processes messages

MESSAGES:

WM_COMMAND    - application menu (About dialog box)
WM_DESTROY    - destroy window

COMMENTS:

To process the IDM_ABOUT message, call MakeProcInstance() to get the
current instance address of the About() function.  Then call Dialog
box which will create the box according to the information in your
generic.rc file and turn control over to the About() function.  When
it returns, free the intance address.

****************************************************************************/

LRESULT CALLBACK 
axMainWndProc( HWND hWnd, UINT message, WPARAM uParam, LPARAM lParam)
{
    FARPROC lpProcAbout;  // pointer to the "About" function
    int wmId, wmEvent;

    switch (message) {
      case WM_CREATE:
	    axMakeInternalWindows(hWnd, (LPCREATESTRUCT) lParam);
	    axMainWnd = hWnd;
	    break;
      case WM_SIZE:
	    axResizeInternalWindows(LOWORD(lParam), HIWORD(lParam));
	    break;

      case WM_DoAxiomCall:
	    axDoCall(uParam, lParam);
	    break;
      case WM_SYSCOMMAND:
	wmId = uParam;
	switch (wmId) {
	case IDM_Interrupt:
	  axInterrupted = TRUE;
	  axCmdKillQueue();
	  break;
	case SC_CLOSE:
	  axInterrupted = TRUE;
	  return DefWindowProc(hWnd, message, uParam, lParam);
	  break;
	default:
	  return DefWindowProc(hWnd, message, uParam, lParam);
	}
	break;
      case WM_COMMAND:  // message: command from application menu
            wmId    = LOWORD(uParam);
            wmEvent = HIWORD(uParam);

            switch (wmId) {
	    case IDM_ABOUT:
	      lpProcAbout = MakeProcInstance((FARPROC)axAbout, hInst);

	      DialogBox(hInst,           // current instance
                        MAKEINTRESOURCE(IDD_ABOUTBOX), // dlg resource to use
                        hWnd,                  // parent handle
                        (DLGPROC)lpProcAbout); // About() instance address

	      break;

	    case IDM_EXIT:
	        axInterrupted = TRUE;
                DestroyWindow (hWnd);
                break;

              case IDM_HELPCONTENTS:
                if (!WinHelp (hWnd, "AXIOM.HLP", HELP_KEY,
			      (DWORD)(LPSTR)"CONTENTS")) {
                        MessageBox (GetFocus(),
                                "Unable to activate help",
                                szAppName, MB_SYSTEMMODAL|MB_OK|MB_ICONHAND);
                }
                break;

              case IDM_HELPSEARCH:
                if (!WinHelp(hWnd, "AXIOM.HLP", HELP_PARTIALKEY,
			     (DWORD)(LPSTR)"")) {
                        MessageBox (GetFocus(),
                                "Unable to activate help",
                                szAppName, MB_SYSTEMMODAL|MB_OK|MB_ICONHAND);
                }
                break;

              case IDM_HELPHELP:
                if(!WinHelp(hWnd, (LPSTR)NULL, HELP_HELPONHELP, 0)) {
                        MessageBox (GetFocus(),
                                "Unable to activate help",
                                szAppName, MB_SYSTEMMODAL|MB_OK|MB_ICONHAND);
                }
                break;

	      case IDM_DoInputAsSpad:
		axDoInput(AXIOM_EXPRESSION_IS_AXIOM);
		break;
	      case IDM_DoInputAsLisp:
		axDoInput(AXIOM_EXPRESSION_IS_LISP);
		break;
	      case IDM_DoInputAsBoot:
		axDoInput(AXIOM_EXPRESSION_IS_BOOT);
		break;
		
	      case IDM_Interrupt:
		axInterrupted = TRUE;
		axCmdKillQueue();
		break;

              // Here are all the other possible menu options,
              // all of these are currently disabled:
              case IDM_NEW:
              case IDM_OPEN:
              case IDM_SAVE:
              case IDM_SAVEAS:
              case IDM_UNDO:
              case IDM_CUT:
              case IDM_COPY:
              case IDM_PASTE:
              case IDM_LINK:
              case IDM_LINKS:

              default:
                return (DefWindowProc(hWnd, message, uParam, lParam));
            }
            break;

        case WM_PAINT:    // message: window being painted
            {
	      PAINTSTRUCT ps;
	      HDC hdc = BeginPaint (hWnd, &ps);
              EndPaint(hWnd, &ps);
            }
            break;

        case WM_INITMENU:
	    axSwitchMenus(axRunningState);
	    break;

        case WM_DESTROY:  // message: window being destroyed
	    PostQuitMessage(0);
            break;

        default:          // Passes it on if unproccessed
            return (DefWindowProc(hWnd, message, uParam, lParam));
    }
    return (0);
}

static void
axMakeInternalWindows(HWND hWnd, LPCREATESTRUCT info)
{
	axOutControl = CreateWindow("edit",
				    NULL,
				    WS_CHILD| WS_VISIBLE | WS_VSCROLL 
				    | WS_HSCROLL | ES_LEFT | ES_MULTILINE
				    | ES_AUTOHSCROLL | ES_AUTOVSCROLL
				    | ES_READONLY,
				    0,0,0,0,
				    hWnd, (void*)108,
				    (info->hInstance),
				    (void*) NULL);
				    
	axInControl = CreateWindow("edit",
				    NULL,
				    WS_CHILD| WS_VISIBLE | WS_VSCROLL 
				    | WS_HSCROLL | ES_LEFT | ES_MULTILINE
				    | ES_AUTOHSCROLL | ES_AUTOVSCROLL,
				    0,0,0,0,
				    hWnd, (void*)107,
				    (info->hInstance),
				    (void*) NULL);
				    
}

static void
axResizeInternalWindows(int width, int height)
{
	    MoveWindow(axOutControl,
		       0,0, 
		       width,
		       (2*height)/3,
		       TRUE);
	    MoveWindow(axInControl, 
		       0,
		       (2*height)/3, 
		       width,
		       height/3, 
		       TRUE);
}

static void
axDoInput(int type)
{
  AxiomCall call = (AxiomCall) malloc(sizeof(*call));
  char buf[1024];
  
  GetWindowText(axInControl, buf, 1024);
  call->handle = NULL;
  call->input  = NULL;
  call->file   = "tmp.tex";
  call->expr   = buf;
  call->opt1   = "";
  call->opt2   = "";
  call->type   = (short) type;
  axCmdAdd(call);
  axDoCall(0, (LPARAM) call);
  SetWindowText(axInControl, "");
}

/****************************************************************************

        FUNCTION: CenterWindow (HWND, HWND)

        PURPOSE:  Center one window over another

        COMMENTS:

        Dialog boxes take on the screen position that they were designed at,
        which is not always appropriate. Centering the dialog over a particular
        window usually results in a better position.

****************************************************************************/

BOOL CenterWindow (HWND hwndChild, HWND hwndParent)
{
    RECT    rChild, rParent;
    int     wChild, hChild, wParent, hParent;
    int     wScreen, hScreen, xNew, yNew;
    HDC     hdc;

    // Get the Height and Width of the child window
    GetWindowRect (hwndChild, &rChild);
    wChild = rChild.right - rChild.left;
    hChild = rChild.bottom - rChild.top;

    // Get the Height and Width of the parent window
    GetWindowRect (hwndParent, &rParent);
    wParent = rParent.right - rParent.left;
    hParent = rParent.bottom - rParent.top;

    // Get the display limits
    hdc = GetDC (hwndChild);
    wScreen = GetDeviceCaps (hdc, HORZRES);
    hScreen = GetDeviceCaps (hdc, VERTRES);
    ReleaseDC (hwndChild, hdc);

    // Calculate new X position, then adjust for screen
    xNew = rParent.left + ((wParent - wChild) /2);
    if (xNew < 0) {
            xNew = 0;
    } else if ((xNew+wChild) > wScreen) {
            xNew = wScreen - wChild;
    }

    // Calculate new Y position, then adjust for screen
    yNew = rParent.top  + ((hParent - hChild) /2);
    if (yNew < 0) {
            yNew = 0;
    } else if ((yNew+hChild) > hScreen) {
            yNew = hScreen - hChild;
    }

    // Set it, and return
    return SetWindowPos (hwndChild, NULL,
            xNew, yNew, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}


/****************************************************************************

        FUNCTION: axAbout(HWND, UINT, WPARAM, LPARAM)

        PURPOSE:  Processes messages for "About" dialog box

        MESSAGES:

        WM_INITDIALOG - initialize dialog box
        WM_COMMAND    - Input received

        COMMENTS:

        Display version information from the version section of the
        application resource.

        Wait for user to click on "Ok" button, then close the dialog box.

****************************************************************************/

LRESULT CALLBACK axAbout(
                HWND hDlg,           // window handle of the dialog box
                UINT message,        // type of message
                WPARAM uParam,       // message-specific information
                LPARAM /* lParam*/)
{
        static  HFONT hfontDlg;
        LPSTR   lpVersion;
        DWORD   dwVerInfoSize;
        DWORD   dwVerHnd;
        UINT    uVersionLen;
        WORD    wRootLen;
        BOOL    bRetCode;
        int     i;
        char    szFullPath[256];
        char    szResult[256];
        char    szGetName[256];

        switch (message) {
                case WM_INITDIALOG:  // message: initialize dialog box
		  // Center the dialog over the application window
		    CenterWindow (hDlg, GetWindow (hDlg, GW_OWNER));
		  
		  // Get version information from the application
		    GetModuleFileName (hInst, szFullPath,
				       sizeof(szFullPath));
		  dwVerInfoSize = GetFileVersionInfoSize(szFullPath, 
							       &dwVerHnd);
		  if (dwVerInfoSize) {
		    // If we were able to get the information,
		    // process it:
		    LPSTR   lpstrVffInfo;
		    HANDLE  hMem;
		    hMem = GlobalAlloc(GMEM_MOVEABLE,
				       dwVerInfoSize);
		    lpstrVffInfo  = (char *) GlobalLock(hMem);
		    GetFileVersionInfo(szFullPath, dwVerHnd,
				       dwVerInfoSize,
				       lpstrVffInfo);
		    lstrcpy(szGetName, 
			    "\\StringFileInfo\\040904e4\\");
		    wRootLen = (WORD) lstrlen(szGetName);
		    
		    // Walk through the dialog items
		      // that we want to replace:
		      for (i = IDC_FILEDESCRIPTION; 
			   i <= IDC_LEGALTRADEMARKS; i++) {
			GetDlgItemText(hDlg, i, szResult,
				       sizeof(szResult));
			szGetName[wRootLen] = (char)0;
			lstrcat (szGetName, szResult);
			uVersionLen   = 0;
			lpVersion     = NULL;
			bRetCode      = VerQueryValue((const LPVOID)
						      lpstrVffInfo,
						      (LPSTR)szGetName,
						      (LPVOID*)&lpVersion,
						      (PUINT)&uVersionLen);
			// For MIPS strictness
			  
			  if ( bRetCode && uVersionLen && lpVersion) {
			    // Replace dialog item text with version info
			      lstrcpy(szResult, lpVersion);
			    SetDlgItemText(hDlg, i, szResult);
			  }
		      }
		    
		    GlobalUnlock(hMem);
		    GlobalFree(hMem);
		  } // if (dwVerInfoSize)
		    // Create a font to use
		      hfontDlg = CreateFont(12, 0, 0, 0, 0, 0, 0, 0,
					    0, 0, 0, 0,
					    VARIABLE_PITCH | FF_SWISS, "");
		  
		  // Walk through the dialog items and change font
		    for (i = IDC_FILEDESCRIPTION;
			 i <= IDC_LEGALTRADEMARKS; i++)
		      SendMessage (GetDlgItem (hDlg, i), WM_SETFONT,
				   (UINT)hfontDlg, TRUE);

		  return (TRUE);
		  
                case WM_COMMAND:                      // message: received a command
		  if (LOWORD(uParam) == IDOK        // "OK" box selected?
		      || LOWORD(uParam) == IDCANCEL) { 
		    // System menu close command?
		      EndDialog(hDlg, TRUE);        // Exit the dialog
			DeleteObject (hfontDlg);
		    return (long) TRUE;
		  }
		  break;
		}
        return FALSE; // Didn't process the message

}

extern "C" {
void
axPollForMessages()
{
  MSG msg;
  int res;

  while (PeekMessage(&msg, NULL, 0, ~(UINT) 0, PM_NOREMOVE)) {
    if (msg.message == WM_QUIT) {
	axInterrupted = TRUE;
	axRunningState = RS_Exit;
        break;
    }
    res = GetMessage(&msg, NULL, 0, 0);
    if (!res) PostQuitMessage(msg.wParam);
    else if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }    
  }
}

int
axGetInterrupt()
{
  return axInterrupted;
}

void
axResetInterrupt()
{
  axInterrupted = 0;
}

}

static void
axSwitchMenus(AxRunState state)
{
  static BOOL doneInit = FALSE;
  HMENU menu 	 = GetMenu(axMainWnd);
  HMENU evalMenu = GetSubMenu(menu, 1);
  HMENU sysMenu = GetSystemMenu(axMainWnd, FALSE);
  BOOL  evalState, intrState;

  if (!doneInit) {
    doneInit = TRUE;
    AppendMenu(sysMenu,		// handle to menu
	       MF_SEPARATOR,	// menu item flags
	       0,	// menu item identifier or pop-up menu handle 
	       NULL	// menu item content
	       );
    AppendMenu(sysMenu,
	       MF_STRING | MF_ENABLED,
	       IDM_Interrupt,
	       "Interrupt!");
  }

  switch (state) {
  case RS_Init:
    evalState = FALSE;
    intrState = FALSE;
    break;
  case RS_Idle:
    evalState = TRUE;
    intrState = FALSE;
    break;
  case RS_Exec:
    evalState = FALSE;
    intrState = TRUE;
    break;
  case RS_Input:
    evalState = TRUE;
    intrState = FALSE;
    break;
  default:
    break;
  }
  EnableMenuItem(evalMenu, IDM_Interrupt,   
		 intrState ? MF_ENABLED : MF_GRAYED); 
  EnableMenuItem(sysMenu, IDM_Interrupt,
		 intrState ? MF_ENABLED : MF_GRAYED);
 EnableMenuItem(evalMenu, IDM_DoInputAsSpad, 
		 evalState ? MF_ENABLED : MF_GRAYED);
  EnableMenuItem(evalMenu, IDM_DoInputAsLisp, 
		 evalState ? MF_ENABLED : MF_GRAYED);
}
 

// !! Axiom

static BOOL
axStartCcl(LPSTR cmdLine)
{
	char *args[axCclNArgs+1];
	char newLibs[axArgsNImages][256];
	char *root;

	int i, nargs;
	nargs = axCclNArgs;

	if (!axInitialiseEnv())
	  return FALSE;
	if (strstr(cmdLine, "-") && !strstr(cmdLine, "mbedd")) {
		char *str = cmdLine;
		nargs = 0;
	  	while (*str != '\0' && nargs < 16) {
	    		while (*str == ' ' && *str != '\0') str ++;
			if (*str != '\0')
	      			args[nargs++] = str;
	      		while (*str != ' ' && *str !='\0') str++;
		}
	} 
	else {
		for (i=0; i< nargs; i++) 
			args[i] = axCclArgs[i];
	  	args[axCclNArgs] = NULL;
	  	if ((root=axGetEnv("AXIOM")) == NULL) {
		  MessageBox(NULL, "No Axiom location: Aborting",
			     "Axiom",
			     MB_OK);
		  return FALSE;
		}
    		for (i=0; i < axArgsNImages ; i++) {
      			sprintf(newLibs[i], "%s/../../share/images/%s", 
	      			root, 
				axCclArgs[axArgsLibStart + 2*i]);
		      		args[axArgsLibStart+2*i] = newLibs[i];
		}
	}
	axRunningState = RS_Init;
	cslstart(nargs, args, axWrite);
	axRunningState = RS_Idle;
	return TRUE;
}

/* define the standard expression processor for external requests */


static short 
axCommandHandler(AxiomCall call)
{
  short ret = AXIOM_RC_SUCCESS;

  if (call == NULL) {
    PostMessage(axMainWnd, WM_DESTROY, 0, 0);
    return ret;
  }
  if (call->type == AXIOM_EXPRESSION_IS_QUIT) {
    PostMessage(axMainWnd, WM_DESTROY, 0, 0);
  }
  else if (strcmp(call->expr, "STOPITNOW") == 0) {
    void *handle = call->handle;
    FILE *foo = fopen(call->file, "w");
    fclose(foo);
    if (axRunningState == RS_Exec) {
      axInterrupted = TRUE;
      axCmdKillQueue();
    }
    EndAxiomCall(call);
    ReleaseAxiomPort(handle);
  }
  else {
    axCmdAdd(call);
    PostMessage(axMainWnd, WM_DoAxiomCall, 0, (LPARAM) call);
  }
  return ret;
}

static void
axDoCall( WPARAM /*wParam*/, LONG /*lParam*/)
{
  	AxiomCall call;
	static int inCall = 0;

	if (inCall)
	  return;
	inCall++;

	while (!axCmdEmpty()) {
	  call = axCmdGetNext();
	  axDoCall0(call);
	}
	inCall--;
}

static void
axDoCall0(AxiomCall call)
{
	char tmpbuf[4];
	char *tmp 		= axNormalizeCall(call);
	void  	   *handle	= call->handle;
	const char *pFileName   = call->file;
	const char *pExpression = call->expr;
	const char *pExtra1	= call->opt1;
	const char *pExtra2     = call->opt2;
	short	    nExprType   = (short) call->type;
	int	    res;

	axRunningState = RS_Exec;

	if (axBeNoisy) {
		MessageBox(NULL, pFileName ? pFileName : "No name", 
			   "x", MB_OK);
		MessageBox(NULL, pExpression ? pExpression : "No expr",
			   "y", MB_OK);
	}

	axfInitBuffer();
	tmpbuf[0] = (char) (nExprType & 0xff);
	tmpbuf[1] = (char) ((nExprType & 0xff00) >> 8);
	axfAddChars(2, tmpbuf);

	/* Stuff the strings into the comms buffer 
	 * the '+1' is the 0 char used to separate the
	 * strings
	 */
	axfAddChars(strlen(pFileName)  +1, pFileName);
	axfAddChars(strlen(pExpression)+1, pExpression);
	axfAddChars(strlen(pExtra1)    +1, pExtra1);
	axfAddChars(strlen(pExtra2)    +1, pExtra2);

	/* This does return a value --- not sure what though */
	axOutputHandle = handle;
	axThisCall = call;
	if ( (res = setjmp(axContext.buf)) == 0) {
	  execute_lisp_function(axFunc, axRead, axWrite);
	  axWrite('\n');
	} 

	axOutputHandle = NULL;
	bufFree(axLineOutput);
	axCleanupCall(tmp);
	axLineOutput = NULL;
	axThisCall   = NULL;

	if (axBeNoisy) {
		MessageBox(NULL, "Done!", "x", MB_OK);
	}
	
	if (handle) {
		EndAxiomCall(call);
		ReleaseAxiomPort(handle);
	}
	else
	  free(call);

	axRunningState = RS_Idle;
}

/*
 * Call normalization functions 
 */
static char *axCallToFile(const char *);
static char axNewCmd[PATH_MAX+1];

static char *
axNormalizeCall(AxiomCall call)
{
  const char *p;
  
  p = call->expr;
  while (*p != '\0') {
    if (*p == '\n') {
      p = call->expr;
      call->expr = axNewCmd;
      return axCallToFile(p);
    }
    p++;
  }
  return NULL;
}

static void
axCleanupCall(char *v)
{
  if (v == NULL)
    return;
  
  DeleteFile(v);
  free(v);
}

/* We can statically allocate this 
 * providing that we normalize immediately
 * before calling
 */

static char *
axCallToFile(const char *cmd)
{
  char *nam, *dir, *p;
  FILE *file;
  
  dir = axGetEnv("TEMP");
  if (!dir) 
    dir = axGetEnv("TMP");
  if (!dir) 
    dir = "";
  sprintf(axNewCmd, "%s\\foo.input", dir);
  nam = (char *)malloc(strlen(axNewCmd) + 1);
  strcpy(nam, axNewCmd);
  file = fopen(nam, "w");
  fputs(cmd, file);
  fclose(file);
  p=dir;
  while (*p!='\0') {
    if (*p == '\\') *p = '/';
    p++;
  }
  sprintf(axNewCmd, ")read %s\\foo", dir );
  return nam;
}

extern "C" char *
axGetEnv(char *s)
{
/*
 * Case fold for MSDOS
 */
    char uppercase[512];
    int c;
    char *p = uppercase;
    while ((c = *s++) != 0) *p++ = (char) toupper(c);
    *p = 0;
    s = uppercase;
    if ( (p=getenv(s)) != NULL)
      return p;
    
    return axGetRegistryEnvItem(s);
}


static BOOL
axInitialiseEnv()
{
  char *val;
  val = axGetEnv("AXIOM");
/* This needs a help screen */
  if (!val) {
    	MessageBox(NULL, 
		   "The AXIOM environment variable is unset.",
		   "AXIOM",
		   MB_OK);
	return 0;
  }
  val = axGetEnv("LM_LICENSE_FILE");
  if (!val) {
    	MessageBox(NULL, 
		   "The LM_LICENSE_FILE environment variable is unset.",
		   "AXIOM",
		   MB_OK);
	return 0;
  }
  //if (!SetEnvironmentVariable("LM_LICENSE_FILE", val))
  //  	MessageBox(NULL, "Yowzer!", "", MB_OK);
  val = (char *)GetEnvironmentStrings();
  printf("%s", val);
  return 1;
}


static char *
axGetRegistryEnvItem(char *s)
{
  HKEY key;
  static BYTE buf[256];
  char *p=(char *)buf;
  DWORD type, size;
  
  key = rgGetSoftwareKey();
  key = rgGetSubKey(key, REG_NONE, 
		    "The Numerical Algorithms Group");
  key = rgGetSubKey(key, REG_NONE, "Axiom");
  key = rgGetSubKey(key, REG_NONE, "Server Properties");
  
  size = 256;
  if (RegQueryValueEx(key, s, NULL, &type, buf, &size)
      != ERROR_SUCCESS)
    p = NULL;
  RegCloseKey(key);

  return (char *) p;
}


static HKEY
rgGetSoftwareKey()
{
  HKEY softKey;

  RegOpenKeyEx(HKEY_CURRENT_USER, "Software", 0, 
	       KEY_READ|KEY_WRITE, &softKey);
  return softKey;
}

static HKEY
rgGetSubKey(HKEY parent, const char *cls, const char *name)
{
  HKEY  child;
  DWORD dw;
  if (!parent)
    return NULL;
  
  if (RegCreateKeyEx(parent, name, 0, (char *) cls, 
		     REG_OPTION_NON_VOLATILE,
		     KEY_WRITE|KEY_READ,
		     NULL,
		     &child,
		     &dw) != ERROR_SUCCESS) {
    child = NULL;
  }
  RegCloseKey(parent);
  return child;
}

void *
axGetCallHandle()
{
  return axThisCall->input;
}

typedef struct _AxCmdList {
  AxiomCall 	      call;
  struct _AxCmdList *next;
} *AxCmdList;

static AxCmdList axCmds = NULL;

static void
axCmdAdd(AxiomCall call)
{
  EnterCriticalSection(&axCmdSem);
  AxCmdList newnode = (AxCmdList) malloc(sizeof(*newnode));
  AxCmdList *last = &axCmds;
  while (*last != NULL) last = &(*last)->next;
  newnode->call = call;
  newnode->next = NULL;
  *last = newnode;
  LeaveCriticalSection(&axCmdSem);
}

static AxiomCall
axCmdGetNext()
{
  EnterCriticalSection(&axCmdSem);
  AxiomCall call = axCmds->call;
  AxCmdList lst = axCmds;
  axCmds = axCmds->next;
  free(lst);
  LeaveCriticalSection(&axCmdSem);
  return call;
}

static void
axCmdKillQueue()
{
  EnterCriticalSection(&axCmdSem);
  while (axCmds != NULL) {
    void *handle;
    AxCmdList lst = axCmds;
    axCmds = axCmds->next;

    handle = lst->call->handle;
    if (handle == NULL)
      free(axCmds->call);
    else {
      if (strlen(lst->call->file) != 0) {
	FILE *foo=fopen(lst->call->file, "w");
	fclose(foo);
      }
      EndAxiomCall(lst->call);
      ReleaseAxiomPort(handle);
    }
    free(lst);
  }
  LeaveCriticalSection(&axCmdSem);
}

static BOOL
axCmdEmpty()
{
  BOOL flg;
  EnterCriticalSection(&axCmdSem);
  flg =(axCmds == NULL);
  LeaveCriticalSection(&axCmdSem);
  return flg;
}

// !! AXIOM
