/*
 * @Description: Entry of postgresql
 * @Author: xum07
 * @Date: 2022-10-31
 * @UpdateData: 2022-10-31
 */
#include "PgEntry.h"
#include "Database.h"
#include "common/Common.h"
#include "common/util/Log.h"
#include "connect_pool/ConnectPool.h"

using namespace LayoutDB_PG;
using namespace LayoutDB;

uint PGEntry::init()
{
    auto ret = createDatabase();
    if (!ret) {
        return INIT_FAILED;
    }

    Singleton<ConnectPool>::create(2);
}

uint PGEntry::exit()
{
    Singleton<ConnectPool>::destory();
}

uint PGEntry::createDatabase()
{
    auto ret = DatabaseManager::create(LAYOUT_DB_NAME);
    if (!ret) {
        return CREATE_DATABASE_FAILED;
    }

    return RET_OK;
}