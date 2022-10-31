/*
 * @Description: Member of school
 * @Author: xum07
 * @Date: 2022-10-28
 * @UpdateData: 2022-10-31
 */
#ifndef LAYOUT_DB_TEST_SCHOOL_MEMBER
#define LAYOUT_DB_TEST_SCHOOL_MEMBER

#include <sys/types.h>
#include <cstring>

namespace LayoutDBTest {
class SchoolMem {
public:
    SchoolMem() = default;
    virtual ~SchoolMem() = default;

    uint getId() { return id_; }
    void setId(uint id) { id_ = id; }
    const std::string& getName() { return name_; }
    void setName(const std::string& name) { name_ = name; }

private:
    uint id_;
    std::string name_;
};
}

#endif  // LAYOUT_DB_TEST_SCHOOL_MEMBER