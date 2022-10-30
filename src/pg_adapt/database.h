/*
 * @Description: Manage database space in PostgreSQL
 * @Author: xum07
 * @Date: 2022-10-30
 */
#ifndef LAYOUT_DB_PG_ADAPT_DATABASE
#define LAYOUT_DB_PG_ADAPT_DATABASE

#include <string_view>

namespace LayoutDB {

class DatabaseManager {
public:
    DatabaseManager() = default;
    virtual ~DatabaseManager() = default;

    static bool create(std::string_view name);
    static bool drop(std::string_view name);
};

}  // namespace LayoutDB

#endif  // LAYOUT_DB_PG_ADAPT_DATABASE