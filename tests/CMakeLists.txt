include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

file(GLOB_RECURSE TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(test_ccbb ${TEST_SOURCES} "LinearRouteTest.cpp" "JumpSpaceTest.cpp")

include_directories (${CCBB_SOURCE_DIR}/src)


target_link_libraries(test_ccbb
  PRIVATE
  ccbb
  GTest::GTest
)

add_test(NAME CcbbTest COMMAND test_ccbb)
