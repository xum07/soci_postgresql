set(ut_name connect_pool_test)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_FILES)
add_executable(${ut_name} ${SRC_FILES})
target_link_libraries(${ut_name} PRIVATE
  gtest
  gtest_main
  pthread
  connect_pool
)

enable_testing()
add_test(${ut_name} COMMAND ${ut_name})