#ifndef __TEST_H_
#define __TEST_H_

#include <stdio.h>
#include <stdbool.h>

typedef int (*test_func_t)(void);


typedef struct {
    const char* name;
    test_func_t func;
    int skip;
} test_case_t;

extern test_case_t tests[1024];
extern int test_count;
extern bool save_resoults;
extern const char* output_path;

#define TEST_CASE(name) int name(void); \
    __attribute__((constructor)) static void register_##name(void) { \
        tests[test_count++] = (test_case_t){#name, name}; \
    } \
    int name(void)

#define TEST_CASE_SKIP(name) \
    int name(void); \
    __attribute__((constructor)) static void register_##name(void) { \
        tests[test_count++] = (test_case_t){#name, name, 1}; \
    } \
    int name(void)

#define REQUIRE(condition)  \
    do { \
        if (!(condition)) { \
            printf("\033[31m[FAIL]\033[0m %s:%d: Assertion `%s` failed,", __FILE__, __LINE__, #condition); \
            return 1; \
        } \
    } while(0)

#define REQUIRE_EQ(a, b) \
    do { \
        int _a = (a); \
        int _b = (b); \
        if (_a != _b) { \
            printf("\033[31m[FAIL]\033[0m %s:%d: %d is not equal to %d,", __FILE__, __LINE__, _a, _b); \
            return 1; \
        } \
    } while (0)
#ifdef __cplusplus
#include <stdexcept>
#define REQUIRE_THROW(expr, ex_type) \
    do { \
        bool _caught = false; \
        try { \
            expr; \
        } catch (const ex_type&) { \
            _caught = true; \
        } catch (...) { \
            return 1; \
        } \
        if (!_caught) { \
            printf("\033[31m[FAIL]\033[0m %s:%d: Function didn't throw requested exception,", __FILE__, __LINE__); \
            return 1; \
        } \
    } while (0)
#endif //__cplusplus
#endif // __TEST_H_
