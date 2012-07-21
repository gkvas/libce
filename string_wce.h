#ifndef _STRING_WCE_H_
#define _STRING_WCE_H_

#ifdef __cplusplus
extern "C" {
#endif

/* string.c */
char *strdup(const char * str);
/* char *strerror(int errno); */
int strnicmp( const char *s1, const char *s2, size_t count );

//#define strnicmp _strnicmp
#define stricmp _stricmp

int _tcscpy_s(char *strDestination, size_t numberOfElements, const char *strSource);
int strerror_s(char *buffer, size_t sizeInBytes, int errnum);

#ifdef __cplusplus
};
#endif

#endif