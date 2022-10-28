/*
 * @Description: The implement of connection pool
 * @Author: xum07
 * @Date: 2022-10-27
 */
#include "ConnectPool.h"

using namespace LayoutDB;

ConnectPool::ConnectPool()
{
    constexpr std::size_t POOL_SIZE = 16;
    sociPool_ = std::make_unique<soci::connection_pool>(POOL_SIZE);
}

Connect ConnectPool::borrow(int timeout)
{
    std::size_t index = 0;
    auto ret = sociPool_->try_lease(index, timeout);
    if (!ret) {
        return {};
    }

    return { sociPool_->at(index), index };
}

void ConnectPool::returnBack(Connect& connect)
{
    sociPool_->give_back(const_cast<std::size_t>(connect.pos_));
}