//
// Created by Krystle Myrdahl on 2019-01-17.
//

#ifndef UNTITLED2_SECURITYSTUDENT_H
#define UNTITLED2_SECURITYSTUDENT_H

#include "student.h"

class securityStudent : public Student {
public:
    virtual Degree getDegreeType();
    using Student::Student;
private:
    Degree DegreeProgram = SECURITY;
};

#endif //UNTITLED2_SECURITYSTUDENT_H
