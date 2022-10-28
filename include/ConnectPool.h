/*
 * @Description: Connection pool head file
 * @Author: xum07
 * @Date: 2022-10-27
 */
#ifndef LAYOUT_DB_CONNECT_POOL
#define LAYOUT_DB_CONNECT_POOL

#include <connection-pool.h>
#include <memory>
#include "Singleton.h"

namespace LayoutDB {
struct Connect {
   soci::session& sess_ {nullptr};
   const std::size_t pos_ {0}; 
};

class ConnectPool : public Singleton<ConnectPool> {
public:
    static Connect borrow(int timeout = -1);
    static void returnBack(Connect& connect);

protected:
    ConnectPool();
    ~ConnectPool() override = default;

private:
    std::unique_ptr<soci::connection_pool> sociPool_;
};

} // namespace LayoutDB

#endif  // LAYOUT_DB_CONNECT_POOL