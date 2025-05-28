cmake_minimum_required(VERSION 3.16)
project(clearunit C)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.c")
file(GLOB TEST_FILES "${CMAKE_SOURCE_DIR}/tests/*.c")

add_executable(test_runner ${SRC_FILES} ${TEST_FILES})

set(GENERATED_TESTS_TXT "${CMAKE_CURRENT_BINARY_DIR}/generated_tests.txt")
set(GENERATED_TESTS_FILE "${CMAKE_CURRENT_BINARY_DIR}/generated_tests.cmake")

# Target do generowania listy testów
add_custom_command(
    OUTPUT "${GENERATED_TESTS_TXT}"
    COMMAND "$<TARGET_FILE:test_runner>" --list > "${GENERATED_TESTS_TXT}"
    DEPENDS test_runner
    COMMENT "Generowanie listy testów"
)

add_custom_target(generate_test_list ALL DEPENDS "${GENERATED_TESTS_TXT}")

# Jeśli plik z listą testów istnieje - wczytaj go i dodaj testy
if(EXISTS "${GENERATED_TESTS_TXT}")
    file(READ "${GENERATED_TESTS_TXT}" TESTS_CONTENT)
    string(REGEX REPLACE "\r?\n" ";" TESTS_LIST "${TESTS_CONTENT}")

    foreach(testname IN LISTS TESTS_LIST)
        if(testname STREQUAL "")
            continue()
        endif()
        add_test(NAME ${testname}
            COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_runner --run ${testname})
    endforeach()
endif()
