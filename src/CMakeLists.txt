file(GLOB SOURCES "*.cpp")

add_executable(
    ccbb ${SOURCES}
)

target_link_libraries(
  ccbb
)
