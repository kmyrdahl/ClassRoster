//
// Created by Krystle Myrdahl on 2019-01-17.
//

#ifndef UNTITLED2_ROSTER_H
#define UNTITLED2_ROSTER_H

#include <iostream>
#include <string>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"

using namespace std;

class Roster {
public:
    void add(string Id, string FirstName, string LastName, string Email, int Age, int CourseDays1, int CourseDays2, int CourseDays3, Degree DegreeProgram);
    void printAll();
    void printByDegreeProgram(int DegreeProgram);
    void printAverageCourseDays(string Id);
    void printInvalidEmails();
    void remove(string Id);
    ~Roster();
    Student *classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};

#endif //UNTITLED2_ROSTER_H
