add_library(connect_pool SHARED
  ConnectPool.cpp
)
target_link_libraries(connect_pool PUBLIC
  soci_core
  log
)