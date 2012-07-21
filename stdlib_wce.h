#ifndef _STDLIB_WCE_H_
#define _STDLIB_WCE_H_

#ifdef __cplusplus
extern "C" {
#endif

char *getenv(const char *charstuff);
char *_fullpath(char *absPath, const char *relPath, size_t maxLength);

int _wgetenv_s(size_t *pReturnValue, wchar_t *buffer, size_t numberOfElements, const wchar_t *varname);

#ifdef __cplusplus
};
#endif

#endif