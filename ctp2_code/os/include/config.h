/* ctp2_code/os/include/config.h.  Generated from config.h.in by configure.  */
/* ctp2_code/os/include/config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Defined when automake runs yacc and renames the output files */
#define AUTOMAKE_INVOKES_YACC 1

/* In every version */
#define CTP2_ENABLE_SLICDEBUG 1

/* File separator on any other os */
#define FILE_SEP "/"

/* File separator on any other os */
#define FILE_SEPC '/'

/* define if the compiler supports basic C++11 syntax */
#define HAVE_CXX11 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you are compiling on Linux */
#define LINUX 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Maximum length of pathnames */
#define MAX_PATH PATH_MAX

/* Name of package */
#define PACKAGE "ctp2"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* read-only architecture-independent data [PREFIX/share] */
#define PACKAGE_DATADIR "${prefix}/share"

/* Define to the full name of this package. */
#define PACKAGE_NAME "ctp2"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "ctp2 1.2"

/* read-only single-machine data [PREFIX/etc] */
#define PACKAGE_SYSCONFDIR "/home/wq108/ctp2/etc"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "ctp2"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.2"

/* Path separator on any other os */
#define PATH_SEP ":"

/* Path separator on any other os */
#define PATH_SEPC ':'

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Do not use COM */
#define USE_COM_REPLACEMENT 1

/* Enable logging */
/* #undef USE_LOGGING */

/* Use the SDL-library */
#define USE_SDL 1

/* Version number of package */
#define VERSION "1.2"

/* Define to 1 if you are compiling on Windows */
/* #undef WIN32 */

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */

/* Debug Parsers */
#define YYDEBUG 9

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

/* Build final release */
#define _BFR_ 1

/* Enable debugging code */
/* #undef _DEBUG */

/* Enable debug tools */
/* #undef _DEBUGTOOLS */

/* Enable the leak reporter */
/* #undef _DEBUG_MEMORY */

/* Maximum length of pathnames */
#define _MAX_PATH PATH_MAX

/* Enable playtesting features */
/* #undef _PLAYTEST */

/* Tiff uint{16,32} datatype collision prevention */
#define _TIFF_DATA_TYPEDEFS_ 1

/* Define to 1 if you are compiling on Windows */
/* #undef _WINDOWS */

/* Use GNU extensions of glibc */
#define __USE_GNU 1

/* Define to 1 if you are compiling on ARM */
/* #undef __arm__ */
