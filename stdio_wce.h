#ifndef _STDDEF_H_
#define _STDDEF_H_

#ifdef __cplusplus
extern "C" {
#endif

FILE *freopen(const char *filename, const char *mode, FILE *file);
FILE *fdopen( int handle, const char *mode );

int sprintf_s(char *buffer, size_t sizeOfBuffer, const char *format, ... );

#ifdef __cplusplus
};
#endif

#endif