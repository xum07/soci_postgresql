#include "connect_pool/ConnectPool.h"
#include <gtest/gtest.h>

constexpr std::string_view TEST_DATABASE = "test";

TEST(DatabaseTest, create_drop_success)
{
    auto ret = DatabaseManager::create(TEST_DATABASE);
    EXPECT_TRUE(ret);

    ret = DatabaseManager::drop(TEST_DATABASE);
    EXPECT_TRUE(ret);
}