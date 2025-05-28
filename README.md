# ClearUnit — Minimalistic Unit Testing Framework for C

ClearUnit is a lightweight and easy-to-use unit testing framework for C that provides:

- Automatic test registration via constructor attributes
- Clear assertion macros (`REQUIRE`, `REQUIRE_EQ`)
- Support for skipping tests (`TEST_CASE_SKIP`)
- Color-coded output for passed, failed, and skipped tests
- Simple integer return status from tests (0 = pass, non-zero = fail)

---

## Installation

ClearUnit is header-only. Simply include `test.h` in your project and write your tests.

---

## Usage Example

```c
#include "test.h"

TEST_CASE(TestSuccess) {
    REQUIRE_EQ(1, 1);
    return 0;
}

TEST_CASE_SKIP(TestSkipped) {
    return 0;
}

TEST_CASE(TestFail) {
    REQUIRE_EQ(1, 2);
    return 1;
}
```
## Macros

```TEST_CASE(name)``` — defines and registers a test case named name

```TEST_CASE_SKIP(name)``` — defines and registers a test case that will be skipped

```REQUIRE(condition)``` — assertion macro that aborts test on failure

```REQUIRE_EQ(a, b)``` — assertion macro to compare two int value

### C++ Only:

```REQUIRE_THROW(expr, ex_type)``` - assertion macro to check if expr throws the specified exception type
 
## License
This project is licensed under the GNU General Public License v3.0 (GPL-3.0).
