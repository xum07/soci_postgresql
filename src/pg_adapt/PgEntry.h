/*
 * @Description: Entry of postgresql
 * @Author: xum07
 * @Date: 2022-10-31
 * @UpdateData: 2022-10-31
 */
#ifndef LAYOUT_DB_PG_ADAPT_ENTRY
#define LAYOUT_DB_PG_ADAPT_ENTRY

#include "Entry.h"

namespace LayoutDB_PG {
class PGEntry : LayoutDB::Entry {
public:
    PGEntry() = default;
    ~PGEntry() override = default;

    uint init() override;
    uint exit() override;
    uint recovery() override { return RET_OK; };

private:
    uint createDatabase();
};  
}  // namespace LayoutDB_PG


#endif  // LAYOUT_DB_PG_ADAPT_ENTRY