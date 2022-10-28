/*
 * @Description: Teacher in the school
 * @Author: xum07
 * @Date: 2022-10-28
 */
#ifndef TEST_TEACHER
#define TEST_TEACHER

#include "SchoolMember.h"
#include <vector>

namespace TEST {
class Teacher : public SchoolMem {
public:
    Teacher() = default;
    ~Teacher() override = default;

    const std::vector<uint>& getClassroom() { return classrooms_; }
    void addClassroom(uint classroomId) { classrooms_.emplace_back(classroomId); }

private:
    std::vector<uint> classrooms_;
};
}

#endif  // TEST_TEACHER