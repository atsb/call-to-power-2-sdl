#include "c3.h"
#include "cifm_winapi.h"

struct ci_name_cache_t {
	char* source;
	char* dest;
};

static ci_name_cache_t CacheRepo[CI_MAX];
static ci_name_cache_t* Cache[CI_MAX];

int strcasecmp(const char* s1, const char* s2)
{
	while (*s1 && *s2)
	{
		int diff = tolower(*s1) - tolower(*s2);
		if (diff != 0)
			return diff;
		++s1;
		++s2;
	}

	return tolower(*s1) - tolower(*s2);
}

char* strndup(const char* s, size_t n)
{
	size_t length = strnlen_s(s, n);
	char* newStr = (char*)malloc(length + 1);

	if (newStr != NULL)
	{
		strncpy_s(newStr, length + 1, s, length);
		newStr[length] = '\0';
	}

	return newStr;
}

void CachePutFirst(int f) {
	if (!f) return;
	ci_name_cache_t* tmp = Cache[f];
	memmove(Cache + 1, Cache + 0, sizeof(ci_name_cache_t*) * f);
	Cache[0] = tmp;
}

bool ci_FileExists(const char* name) {
	if (!name)
		return true;
	if (name[0] == '\0')
		return true;
	if (strcmp(name, "/") == 0)
		return true;

	DWORD dwAttrib = GetFileAttributesA(name);
	return (dwAttrib != INVALID_FILE_ATTRIBUTES);
}

const char* get_name(const char* name) {
	static int inited = 0;
	static char* tmp_c[8];
	static int tmp_i = 0;

	if (!inited) {
		for (int i = 0; i < CI_MAX; i++) {
			CacheRepo[i].source = (char*)malloc(MAX_PATH);
			CacheRepo[i].dest = (char*)malloc(MAX_PATH);
			CacheRepo[i].source[0] = '\0';
			CacheRepo[i].dest[0] = '\0';
			Cache[i] = &CacheRepo[i];
		}
		for (int i = 0; i < 8; i++) {
			tmp_c[i] = (char*)malloc(MAX_PATH);
			tmp_c[i][0] = '\0';
		}
		inited = 1;
	}

	if (!name)
		return name;
	if (name[0] == '\0')
		return name;
	if (strcmp(name, "/") == 0)
		return name;
	if (ci_FileExists(name)) {

		return name;
	}
#define TMP(a) char* p##a = tmp_c[tmp_i]; tmp_i=(tmp_i+1)&7
	if (strchr(name, '\\')) {
		TMP(1);
		strcpy_s(p1, MAX_PATH, name);
		char* p = p1;
		while ((p = strchr(p, '\\')))
			*p = '/';
		return get_name(p1);
	}
	if (name[strlen(name) - 1] == '/') {
		TMP(1);
		strcpy_s(p1, MAX_PATH, name);
		p1[strlen(name) - 1] = '\0';
		TMP(2);
		strcpy_s(p2, MAX_PATH, get_name(p1));
		strcat_s(p2, MAX_PATH, "/");
		return p2;
	}

	// search in repo...
	for (int i = 0; i < CI_MAX; i++)
		if (strcasecmp(name, Cache[i]->source) == 0)
			if (ci_FileExists(Cache[i]->dest)) {
				//test if ok first, then return the value
				CachePutFirst(i);
				return Cache[0]->dest;
			}

	// split name / folder
	char* p = (char*)strrchr(name, '/');
	char* r = (p) ? strndup(name, p - name) : NULL;
	char* n = (p) ? _strdup(p + 1) : _strdup(name);

	const char* new_r = get_name(r);

	if (!ci_FileExists(new_r)) {
		// fail to find the right path...
		free(r);
		free(n);
		return name;
	}
	// try to find a match for name now
	HANDLE hFind;
	WIN32_FIND_DATAA findData;
	TMP(1);
	strcpy_s(p1, MAX_PATH, new_r ? new_r : ".");
	strcat_s(p1, MAX_PATH, "\\*");
	hFind = FindFirstFileA(p1, &findData);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (strcasecmp(findData.cFileName, n) == 0) {
				strcpy_s(p1, MAX_PATH, new_r ? new_r : "");
				strcat_s(p1, MAX_PATH, new_r ? "\\" : "");
				strcat_s(p1, MAX_PATH, findData.cFileName);
				if (ci_FileExists(p1)) {
					CachePutFirst(CI_MAX - 1);
					strcpy_s(Cache[0]->source, MAX_PATH, name);
					strcpy_s(Cache[0]->dest, MAX_PATH, p1);
					free(r);
					free(n);
					FindClose(hFind);
					return Cache[0]->dest;
				}
			}
		} while (FindNextFileA(hFind, &findData));
		FindClose(hFind);
	}
	// build something...
	strcpy_s(p1, MAX_PATH, new_r ? new_r : "");
	strcat_s(p1, MAX_PATH, new_r ? "\\" : "");
	strcat_s(p1, MAX_PATH, n);
	// fail
	free(r);
	free(n);

	return p1;
}

const char* CI_FixName(const char* name)
{
	const char* fixedname = get_name(name);

	return fixedname;
}

int CI_FileExists(const char* name)
{
	if (ci_FileExists(name))
		return 1;
	return 0;
}
