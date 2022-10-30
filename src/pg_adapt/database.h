/*
 * @Description: Manage database space in PostgreSQL
 * @Author: xum07
 * @Date: 2022-10-30
 */
#ifndef LAYOUT_DB_PG_DATABASE
#define LAYOUT_DB_PG_DATABASE

namespace LayoutDB {

class DatabaseManager {
public:
    DatabaseManager() = default;
    virtual ~DatabaseManager() = default;

    bool create(std::string_view name);
    bool drop(std::string_view name);
};

}  // namespace LayoutDB

#endif  // LAYOUT_DB_PG_DATABASE