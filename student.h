//
// Created by Krystle Myrdahl on 2019-01-17.
//

#ifndef UNTITLED2_STUDENT_H
#define UNTITLED2_STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {

    int CourseDays[3], Age;
    string Id, FirstName, LastName, Email;




public:
    Degree DegreeType;

    //get

    string getId();

    string getFirstName();

    string getLastName();

    string getEmail();

    int getAge();

    int *getCourseDays();

    Degree getDegreeType;


    //set

    void setId(string);

    void setFirstName(string);

    void setLastName(string);

    void setEmail(string);

    void setAge(int);

    void setCourseDays(int[3]);

    void setDegreeType(Degree);

    void setDegreeProgram(Degree);

    //methods
    Student(string Id, string FirstName, string LastName, string Email, int Age, int* CourseDays, Degree);

    Student();

    ~Student();

    virtual Degree getDegreeProgram();

    virtual void print();




};



#endif //UNTITLED2_STUDENT_H
