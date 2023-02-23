file(GLOB SOURCES "*.cpp")
list(REMOVE_ITEM SOURCES "main.cpp")

add_library(ccbb ${SOURCES})
add_executable(
    play main.cpp
)

target_link_libraries(
  play
  ccbb
)

