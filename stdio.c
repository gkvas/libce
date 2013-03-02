/***************************************************************
  stdio.c
***************************************************************/

#include <windows.h>
#include "wince.h" /* for wce_mbtowc */


FILE *freopen(const char *filename, const char *mode, FILE *file)
{
	wchar_t *wfilename, *wmode;
	FILE *fp;

	wfilename = wce_mbtowc(filename);
	wmode     = wce_mbtowc(mode);

	fp = _wfreopen(wfilename, wmode, file);

	free(wfilename);
	free(wmode);

	return fp;
}

FILE *fdopen( int handle, const char *mode )
{
	wchar_t *wmode;
	FILE* fp;

	wmode = wce_mbtowc(mode);
	fp = _wfdopen( (void*)handle, wmode );

	free(wmode);
	return fp;
}

errno_t fopen_s(FILE **file, const char *filename, const char *mode) {
	FILE* p;
	
	if(file == NULL || filename == NULL) {
		return EINVAL;
	}
	 p = fopen(filename, mode);

	if(p == NULL) {
		return EINVAL;
	}

	file = &p;

	return 0;
}

int sprintf_s(char *buffer, size_t sizeOfBuffer, const char *format, ... ){
	int ret;
	va_list argptr;
    va_start(argptr, format);
	ret = sprintf(buffer, format, argptr);
	va_end(argptr);
	return ret;
}

int vsnprintf_s(char *buffer, size_t sizeOfBuffer, size_t count, const char *format, va_list argptr ) {
	int ret;
	ret = _vsnprintf(buffer, sizeOfBuffer, format, argptr);    
	return ret;
}

int _vscprintf(const char *format, va_list argptr) {
	char buffer[8192];
	return _vsnprintf(buffer, 8192, format, argptr);
}
