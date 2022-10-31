add_library(pg_adapt SHARED
  Database.cpp
)
target_link_libraries(pg_adapt PUBLIC
  soci_core
  soci_postgresql
  pq
  log
)