/*
 * @Description: The test class of ConnectPool
 * @Author: xum07
 * @Date: 2022-10-28
 */
#include "connect_pool/ConnectPool.h"
#include <gtest/gtest.h>
#include <thread>
#include <chrono>
#include "util/Log.h"

using namespace LayoutDB;
using namespace std::chrono_literals;

namespace {
static void usePool(const std::chrono::seconds& sec, int timeout) {
    auto id = std::this_thread::get_id();
    auto conn = Singleton<ConnectPool>::inst()->borrow(timeout);
    if (!conn.has_value()) {
        Log() << "thread [" << id << "] fail to borrow" << std::endl;
        return;
    }

    Log() << "thread[" << id << "] borrow a session" << std::endl;
    std::this_thread::sleep_for(sec);
    Singleton<ConnectPool>::inst()->returnBack(conn.value());
    Log() << "thread[" << id << "] release a session" << std::endl;
}
}

TEST(ConnectPoolTest, multi_thread_success)
{
    Singleton<ConnectPool>::create(2);

    std::thread t1(usePool, 4s, -1);
    std::thread t2(usePool, 6s, -1);
    std::thread t3(usePool, 1s, 2);
    std::thread t4(usePool, 1s, -1);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    Singleton<ConnectPool>::destory();
}