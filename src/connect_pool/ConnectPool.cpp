/*
 * @Description: The implement of connection pool
 * @Author: xum07
 * @Date: 2022-10-27
 * @UpdateData: 2022-10-27
 */
#include "connect_pool/ConnectPool.h"
#include <soci/session.h>

using namespace LayoutDB;

ConnectPool::ConnectPool(std::size_t poolSize)
{
    sociPool_ = std::make_unique<soci::connection_pool>(poolSize);
}

std::optional<Connect> ConnectPool::borrow(int timeout)
{
    std::size_t index = 0;
    auto ret = sociPool_->try_lease(index, timeout);
    if (!ret) {
        return std::nullopt_t;
    }

    return Connect(&(sociPool_->at(index)), index);
}

void ConnectPool::returnBack(Connect& connect)
{
    if (connect.sess_->is_connected()) {
        connect.sess_->close();
    }

    sociPool_->give_back(connect.pos_);
}