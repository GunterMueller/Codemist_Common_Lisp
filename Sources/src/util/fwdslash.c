#include <stdio.h>
int
main(int argc, char *argv[])
{
  int c, i;
  char *p;
  for (i=1; i<argc; i++) {
    p = argv[i];
    while (*p != '\0') {
      c = *p;
      if (c == '\\') c='/';
      fputc(c, stdout);
      p++;
    }
  }
  fputc('\n', stdout);
  return 0;
}

