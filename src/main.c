#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "test.h"

int main(int argc, char *argv[]) {
    int passed = 0;
    int skipped = 0;
    if (argc < 2) {

    } else if (strcmp(argv[1], "--list") == 0) {
        for (int i = 0; i < test_count; ++i) {
            printf("%s\n", tests[i].name);
        }
        exit(0);
    } else if (strcmp(argv[1], "--run") == 0 && argc == 3) {
        const char *target = argv[2];
        int found = 0;
        for (int i = 0; i < test_count; ++i) {
            if (strcmp(tests[i].name, target) == 0) {
                found = 1;
                clock_t start = clock();
                int result = tests[i].func();
                clock_t end = clock();
                double elapsed_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
                if (result == 0) {
                    printf("\033[32mPASSED\033[0m, function took %.2f milliseconds\n", elapsed_ms);
                    ++passed;
                    return 0;
                } else {
                    printf("\033[31mFAILED\033[0m, function took %.2f milliseconds\n", elapsed_ms);
                    return 1;
                }
                break;
            }
        }
        exit(0);
        if (!found) {
            printf("Test didn't find: %s\n", target);
        }
    } else {
        printf("Bad argument.");
    }

    

    printf("Starting ClearUnit\n");

    for (int i = 0; i < test_count; ++i) {
        if (tests[i].skip) {
            printf("Skipping %s\n", tests[i].name);
            ++skipped;
            continue;
        }
        
        clock_t start = clock();
        printf("Running %s... ", tests[i].name);
        int result = tests[i].func();
        clock_t end = clock();

        double elapsed_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        if (result == 0) {
            printf("\033[32mPASSED\033[0m, function took %.2f milliseconds\n", elapsed_ms);
            ++passed;
        } else {
            printf(" function took %.2f milliseconds\n", elapsed_ms);
        }
    }

    printf("\nSummary: %d/%d tests passed, %d skipped\n", passed, test_count, skipped);
    return passed == test_count - skipped ? 0 : 1;
}
