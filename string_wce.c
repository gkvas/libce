/***************************************************************
  string.c
***************************************************************/

#include <windows.h>
#include "wince.h" /* for wce_mbtowc */

/* _strdup already exists in stdlib.h? */
char *strdup(const char * str)
{
	char *p;

	p = malloc( strlen(str)+1 );
	strcpy( p, str );
	return p;
}

char* strerror(int errno)
{
	static char buf[32]="wince::strerror called.";
	return buf;
}

/* strnicmp already exists in stdlib.h? */
int strnicmp( const char *s1, const char *s2, size_t count )
{
	wchar_t *w1, *w2;
	int n;

	w1 = wce_mbtowc(s1);
	w2 = wce_mbtowc(s2);

	n = wcsnicmp(w1, w2, count);

	free(w1);
	free(w2);

	return n;
}

int strerror_s(char *buffer, size_t sizeInBytes, int errnum) {

	char* err_str = strerror(errnum);

	strncpy(buffer, err_str, strlen(err_str));

	return 0;
}