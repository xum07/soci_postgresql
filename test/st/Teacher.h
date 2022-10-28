/*
 * @Description: Teacher in the school
 * @Author: xum07
 * @Date: 2022-10-28
 */
#ifndef LAYOUT_DB_TEST_TEACHER
#define LAYOUT_DB_TEST_TEACHER

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

#endif  // LAYOUT_DB_TEST_TEACHER