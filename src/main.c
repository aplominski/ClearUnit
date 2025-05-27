#include <stdio.h>
#include "test.h"

int main() {
    int passed = 0;
    int skipped = 0;
    printf("Starting ClearUnit\n");

        for (int i = 0; i < test_count; ++i) {
        if (tests[i].skip) {
            printf("Skipping %s\n", tests[i].name);
            ++skipped;
            continue;
        }

        printf("Running %s... ", tests[i].name);
        int result = tests[i].func();
        if (result == 0) {
            printf("\033[32mPASSED\033[0m\n");
            ++passed;
        }
    }

    printf("\nSummary: %d/%d tests passed, %d skipped\n", passed, test_count, skipped);
    return passed == test_count - skipped ? 0 : 1;
}
