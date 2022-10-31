/*
 * @Description: Students in the school
 * @Author: xum07
 * @Date: 2022-10-28
 * @UpdateData: 2022-10-31
 */
#ifndef LAYOUT_DB_TEST_STUDENT
#define LAYOUT_DB_TEST_STUDENT

#include "SchoolMember.h"

namespace LayoutDBTest {
class Student : public SchoolMem {
public:
    Student() = default;
    ~Student() override = default;

    uint getClassroom() { return classroom_; }
    void setClassroom(uint classroomId) { classroom_ = classroomId; }

private:
    uint classroom_;
};
}

#endif  // LAYOUT_DB_TEST_STUDENT