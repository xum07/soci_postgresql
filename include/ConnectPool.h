/*
 * @Description: Connection pool head file
 * @Author: xum07
 * @Date: 2022-10-27
 */
#ifndef LAYOUT_DB_CONNECT_POOL
#define LAYOUT_DB_CONNECT_POOL

#include <soci/connection-pool.h>
#include <memory>
#include "util/Singleton.h"

namespace LayoutDB {
struct Connect {
   soci::session* sess_ {nullptr};
   const std::size_t pos_ {0};  // internal member of soci::connect_pool, don't change and don't care
};

class ConnectPool : public Singleton<ConnectPool> {
public:
    explicit ConnectPool(std::size_t poolSize);
    ~ConnectPool() override = default;

    Connect borrow(int timeout = -1);
    void returnBack(Connect& connect);

private:
    std::unique_ptr<soci::connection_pool> sociPool_;
};

} // namespace LayoutDB

#endif  // LAYOUT_DB_CONNECT_POOL