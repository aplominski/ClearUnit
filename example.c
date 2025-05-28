#include "test.h"

TEST_CASE(TestEQSuccess) {
    REQUIRE_EQ(1, 1);
    return 0;
}

TEST_CASE(TestEQFail) {
    REQUIRE_EQ(1, 2);
    return 0;
}

TEST_CASE(TestRequireSuccess) {
    REQUIRE(1 == 1);
    return 0;
} 

TEST_CASE(TestRequireFail) {
    REQUIRE(1 != 1);
    return 0;
}