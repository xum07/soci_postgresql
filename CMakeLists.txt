project(PG_TEST)
cmake_minimum_required(VERSION 3.12)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O0 -g -fPIC")
add_compile_options(-Wall -fstack-protector -Wl,-z,noexecstack)

set(OPEN_SOURCE_DIR ${PROJECT_SOURCE_DIR}/opensource)
include_directories(${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src
  ${OPEN_SOURCE_DIR}/postgresql/include
  ${OPEN_SOURCE_DIR}/soci/include
  ${OPEN_SOURCE_DIR}/googletest/include
)
link_directories(${OPEN_SOURCE_DIR}/postgresql/lib
  ${OPEN_SOURCE_DIR}/postgresql/lib
  ${OPEN_SOURCE_DIR}/soci/lib
  ${OPEN_SOURCE_DIR}/googletest/lib
)

add_subdirectory(src)
add_subdirectory(test)