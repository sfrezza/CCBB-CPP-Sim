include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

FetchContent_Declare(
  rapidcheck
  GIT_REPOSITORY https://github.com/emil-e/rapidcheck.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(rapidcheck)

add_library(rc::detail INTERFACE IMPORTED)
target_link_libraries(rc::detail INTERFACE rapidcheck)

file(GLOB_RECURSE TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(test_ccbb ${TEST_SOURCES})

include_directories (${CCBB_SOURCE_DIR}/src)


target_link_libraries(test_ccbb
  PRIVATE
  ccbb
  GTest::GTest
  rc::detail
)

add_test(NAME CcbbTest COMMAND test_ccbb)
