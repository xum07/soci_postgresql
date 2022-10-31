/*
 * @Description: Manage database space in PostgreSQL
 * @Author: xum07
 * @Date: 2022-10-30
 * @UpdateData: 2022-10-30
 */
#include "Database.h"
#include <soci/session.h>
#include "connect_pool/ConnectPool.h"
#include "common/util/Log.h"

using namespace LayoutDB_PG;
using namespace LayoutDB;

bool DatabaseManager::create(std::string_view name)
{
    try {
        session sess("postgresql", "dbname=postgres");
        sess << "create database " << name.data();
    } catch (std::exception& e) {
        Log() << "fail to create database, reson: " << e.what() << std::endl;
        return false;
    }

    return true;
}

bool DatabaseManager::drop(std::string_view name)
{
    try {
        session sess("postgresql", "dbname=postgres");
        sess << "drop database " << name.data();
    } catch (std::exception& e) {
        Log() << "fail to drop database, reson: " << e.what() << std::endl;
        return false;
    }

    return true;
}