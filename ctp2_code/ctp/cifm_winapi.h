#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CI_MAX 64
#ifndef MAX_PATH
#define MAX_PATH 4096
#endif

int strcasecmp(const char* s1, const char* s2);
char* strndup(const char* s, size_t n);
void CachePutFirst(int f);
bool ci_FileExists(const char* name);
const char* get_name(const char* name);
const char* CI_FixName(const char* name);
int CI_FileExists(const char* name);
