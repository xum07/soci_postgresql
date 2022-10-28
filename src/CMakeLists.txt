add_library(connect_pool SHARED
  ConnectPool.cpp
  util/Log.cpp
)
target_link_libraries(connect_pool PUBLIC
  soci_core
  soci_postgresql
  pq
)