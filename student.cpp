//
// Created by Krystle Myrdahl on 2019-01-17.
//

#include <iostream>
#include "student.h"
#include "degree.h"
#include <string>
using namespace std;

Student::Student()
{

}
Student::Student(string Id, string FirstName, string LastName, string Email, int Age, int* CourseDays, Degree)
{

}

string Student::getId() {
    return Id;
}

void Student::setId(string ID)
{
    Student::Id = ID;
}

string Student::getFirstName()
{
    return FirstName;
}

void Student::setFirstName(string firstName)
{
    Student::FirstName = firstName;
}

string Student::getLastName()
{
    return LastName;
}

void Student::setLastName(string lastName)
{
    Student::LastName = lastName;
}

string Student::getEmail()
{
    return Email;
}
void Student::setEmail(string email)
{
    Student::Email = email;
}

int Student::getAge()
{
    return Age;
}

void Student::setAge(int age)
{
    Student::Age = age;
}


int *Student::getCourseDays() {
    return CourseDays;
}

void Student::setCourseDays(int *day)
{
    for (int i = 0; i < 3; i++) {
        CourseDays[i] = day[i];
    }
    Student::CourseDays[0] = day[0];
    Student::CourseDays[1] = day[1];
    Student::CourseDays[2] = day[2];
}

void Student::setDegreeType(Degree degree)
{
    Student::DegreeType = degree;
}



Degree Student::getDegreeProgram() {
    return Degree::SOFTWARE;
}



void Student::print() {}

// default deconstructor definition
Student::~Student()
{

}