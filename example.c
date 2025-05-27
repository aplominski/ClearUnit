#include "test.h"

TEST_CASE(TestSuccess) {
    REQUIRE_EQ(1, 1);
    return 0;
}

TEST_CASE(TestFail) {
    REQUIRE_EQ(1, 2);
    return 0;
}
