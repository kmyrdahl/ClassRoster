//
// Created by Krystle Myrdahl on 2019-01-17.
//

#ifndef UNTITLED2_SOFTWARESTUDENT_H
#define UNTITLED2_SOFTWARESTUDENT_H

#include "student.h"

class softwareStudent : public Student {
public:
    virtual Degree getDegreeType();
    using Student::Student;
private:
    Degree DegreeProgram = SOFTWARE;
};

#endif //UNTITLED2_SOFTWARESTUDENT_H
