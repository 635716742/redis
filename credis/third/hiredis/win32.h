#ifndef _MSC_VER_HELPER_INCLUDE
#define _WIN32_HELPER_INCLUDE
#ifdef _MSC_VER

#ifndef inline
#define inline __inline
#endif

#ifndef va_copy
#define va_copy(d,s) ((d) = (s))
#endif

#ifndef snprintf
#define snprintf _snprintf
#endif

#endif
#endif