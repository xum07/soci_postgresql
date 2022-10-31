/*
 * @Description: Test case of demo
 * @Author: xum07
 * @Date: 2022-10-31
 * @UpdateData: 2022-10-31
 */
#include "Student.h"
#include "Teacher.h"
#include "connect_pool/ConnectPool.h"

using namespace LayoutDBTest;

void DemoTest::SetUpTestCase()
{
    Singleton<ConnectPool>::inst();
}

void DemoTest::TearDownTestCase()
{

}

TEST(DemoTest, create_table_success)
{

}

TEST(DemoTest, insert_row_success)
{

}

TEST(DemoTest, query_success)
{

}

TEST(DemoTest, delete_row_success)
{
    
}