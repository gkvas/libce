#ifndef _STDIO_WCE_H_
#define _STDIO_WCE_H_

#define _TRUNCATE 0

#ifdef __cplusplus
extern "C" {
#endif

FILE *freopen(const char *filename, const char *mode, FILE *file);
FILE *fdopen( int handle, const char *mode );

int sprintf_s(char *buffer, size_t sizeOfBuffer, const char *format, ... );

int vsnprintf_s(char *buffer, size_t sizeOfBuffer, size_t count, const char *format, ... );

int _vscprintf(const char *format, va_list argptr);

int _wopen(const wchar_t *filename, int oflag);

#ifdef __cplusplus
};
#endif

#endif