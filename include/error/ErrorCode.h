/*
 * @Description: Error code
 * @Author: xum07
 * @Date: 2022-10-31
 * @UpdateData: 2022-10-31
 */
#ifndef LAYOUT_DB_ERROR_CODE
#define LAYOUT_DB_ERROR_CODE

namespace LayoutDB {

constexpr uint RET_ERR = 0;
constexpr uint RET_OK = 1;

// 0 ~ 1000 entry
constexpr uint INIT_FAILED = 2;

// 1001 ~ 2000 database
constexpr uint CREATE_DATABASE_FAILED = 1001;

}

#endif  // LAYOUT_DB_ERROR_CODE