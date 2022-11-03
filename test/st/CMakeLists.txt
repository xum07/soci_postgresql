set(st_name st_test)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/demo/*.cpp)
add_executable(${st_name} ${SRC_FILES})
target_link_libraries(${st_name} PRIVATE
  gtest
  gtest_main
  pthread
  connect_pool
  soci_postgresql
  pq
)

enable_testing()
add_test(${st_name} COMMAND ${st_name})