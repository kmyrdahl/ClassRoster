//
// Created by Krystle Myrdahl on 2019-01-17.
//

#ifndef UNTITLED2_NETWORKSTUDENT_H
#define UNTITLED2_NETWORKSTUDENT_H

#include "student.h"

class networkStudent : public Student {
public:
    virtual Degree getDegreeType();
    using Student::Student;
private:
    Degree DegreeProgram = NETWORKING;
};

#endif //UNTITLED2_NETWORKSTUDENT_H
