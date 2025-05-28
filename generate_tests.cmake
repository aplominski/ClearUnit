file(WRITE ${CMAKE_BINARY_DIR}/CTestTestfile.cmake "")
execute_process(
    COMMAND ${TEST_RUNNER} --list
    OUTPUT_VARIABLE TEST_LIST
    RESULT_VARIABLE RES
)

if(NOT RES EQUAL 0)
    message(FATAL_ERROR "Nie udało się pobrać listy testów")
endif()

string(REPLACE "\n" ";" TESTS "${TEST_LIST}")

file(WRITE ${CMAKE_BINARY_DIR}/CTestTestfile.cmake "")

foreach(TEST IN LISTS TESTS)
    if(TEST STREQUAL "")
        continue()
    endif()
    add_test(NAME ${TEST}
         COMMAND ${TEST_RUNNER}
         --run ${TEST})
endforeach()
