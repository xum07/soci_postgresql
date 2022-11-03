/*
 * @Description: Test case of demo
 * @Author: xum07
 * @Date: 2022-10-31
 * @UpdateData: 2022-10-31
 */
#include "Demo.h"
#include <soci/session.h>
#include "connect_pool/ConnectPool.h"
#include "common/util/Log.h"

using namespace LayoutDBTest;
using namespace LayoutDB;

void DemoTest::SetUpTestCase()
{
    Singleton<ConnectPool>::create(1);
}

void DemoTest::TearDownTestCase()
{
    Singleton<ConnectPool>::destory();
}

TEST_F(DemoTest, create_and_drop_table_success)
{
    auto conn = Singleton<ConnectPool>::inst()->borrow();
    ASSERT_NE(conn.sess_, nullptr);
    
    conn.sess_->open("postgresql", "dbname=postgres");
    *conn.sess_ << "create table test1(id int, name text);";
    Singleton<ConnectPool>::inst()->returnBack(conn);
}
