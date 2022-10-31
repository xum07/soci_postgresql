/*
 * @Description: Entry of database
 * @Author: xum07
 * @Date: 2022-10-31
 * @UpdateData: 2022-10-31
 */
#ifndef LAYOUT_DB_ENTRY
#define LAYOUT_DB_ENTRY

#include "error/ErrorCode.h"

namespace LayoutDB {
class Entry {
public:
    Entry() = default;
    virtual ~Entry() = default;

    virtual uint init() { return RET_OK; }
    virtual uint exit() { return RET_OK; }
    virtual uint recover() { return RET_OK; }
};
} // namespace LayoutDB

#endif  // LAYOUT_DB_ENTRY