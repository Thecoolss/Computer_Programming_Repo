#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SA_GET_FILENAME(file)                                                  \
  (strrchr(file, '/')                                                          \
       ? strrchr(file, '/') + 1                                                \
       : (strrchr(file, '\\') ? strrchr(file, '\\') + 1 : file))

#if defined(NDEBUG)
#define super_assert(condition, message) ((void)0)
#else

#if defined(SUPER_ASSERT_VERBOSE) && SUPER_ASSERT_VERBOSE == 1
#define SA_PRINT_CONTEXT()                                                     \
  fprintf(stderr, "[%s:%d %s] ", SA_GET_FILENAME(__FILE__), __LINE__, __func__)
#else
#define SA_PRINT_CONTEXT() ((void)0)
#endif

#if defined(SUPER_ASSERT_TRACE) && SUPER_ASSERT_TRACE == 1
#define SA_TRACE_SUCCESS(message)                                              \
  do {                                                                         \
    SA_PRINT_CONTEXT();                                                        \
    fprintf(stderr, "Assertion passed: %s\n", message);                        \
  } while (0)
#else
#define SA_TRACE_SUCCESS(message) ((void)0)
#endif

#if defined(SUPER_ASSERT_PERMISSIVE) && SUPER_ASSERT_PERMISSIVE == 1
#define SA_HANDLE_FAILURE() ((void)0)
#else
#define SA_HANDLE_FAILURE() abort()
#endif

#define super_assert(condition, message)                                       \
  do {                                                                         \
    if (!(condition)) {                                                        \
      /* Failed assertion */                                                   \
      SA_PRINT_CONTEXT();                                                      \
      fprintf(stderr, "Assertion failed: %s (%s)\n", #condition, message);     \
      SA_HANDLE_FAILURE();                                                     \
    } else {                                                                   \
      /* Passed assertion */                                                   \
      SA_TRACE_SUCCESS(message);                                               \
    }                                                                          \
  } while (0)
#endif
