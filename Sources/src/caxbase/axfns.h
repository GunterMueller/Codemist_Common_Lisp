/* 
 * Talking to ccl 
 */

#ifdef __cplusplus 
extern "C" {
#endif

void  axfInitBuffer	(void);

void  axfAddChars	(int, const char *);

int   axfGetReturnCode	(void);
#ifdef __cplusplus 
}
#endif
