# message(STATUS "main.cpp path: ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

file(GLOB LIB_SOURCES "*.cpp")
# list(REMOVE_ITEM LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

message(STATUS "LIB_SOURCES list: ${LIB_SOURCES}")

add_library(ccbblib ${LIB_SOURCES})
add_executable(ccbb ${LIB_SOURCES} main.cpp)

target_link_libraries(
  ccbblib
)

