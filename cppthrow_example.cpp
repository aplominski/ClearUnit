#include "test.h"
void check_positive(int x) {
    if (x < 0) {
        throw std::runtime_error("Negative value");
    }
}
TEST_CASE(TestThrow) {
    REQUIRE_THROW(check_positive(-1), std::runtime_error);
    return 0;
}