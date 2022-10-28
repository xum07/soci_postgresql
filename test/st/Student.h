/*
 * @Description: Students in the school
 * @Author: xum07
 * @Date: 2022-10-28
 */
#ifndef TEST_STUDENT
#define TEST_STUDENT

#include "SchoolMember.h"

namespace TEST {
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

#endif  // TEST_STUDENT