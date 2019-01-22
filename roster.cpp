//
// Created by Krystle Myrdahl on 2019-01-17.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include "roster.h"

using namespace std;


const int classRosterSize = 5;

const string studentData[] =
        {
                "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
                "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                "A5,Krystle,Myrdahl,kmyrdah@wgu.edu,29,12,8,20,SOFTWARE"
        };

int main() {
    cout << "Scripting and Programming - Applications - C867 \n";
    cout << "C++ \n";
    cout << "Student ID: 000902621 \n";
    cout << "Krystle Myrdahl \n\n";



    Roster classRoster;

    Degree myDegree;




//populate roster array
    for (int i = 0; i < 5; i++) {
        cout << studentData[i] << "\n";
        string input = studentData[i];
        istringstream ss(input);
        string tokens;
        string tempHolder[9];

        int x = 0;
        while (getline(ss, tokens, ',')) {
            tempHolder[x] = tokens;
            x += 1;
        }

        if (tempHolder[8] == "NETWORK") {
            myDegree = NETWORKING;
        } else if (tempHolder[8] == "SECURITY") {
            myDegree = SECURITY;
        } else if (tempHolder[8] == "SOFTWARE") {
            myDegree = SOFTWARE;
        } else{
            myDegree = OTHER;
        }

        classRoster.add(tempHolder[0], tempHolder[1], tempHolder[2], tempHolder[3], stoi(tempHolder[4]),
                        stoi(tempHolder[5]), stoi(tempHolder[6]), stoi(tempHolder[7]), myDegree);




    }
    classRoster.printAll();

    classRoster.printInvalidEmails();

    classRoster.printAverageCourseDays("A1");

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    classRoster.remove("A3");

    return 0;
}


//update roster

void Roster::add(string Id, string FirstName, string LastName, string Email, int Age, int CourseDays1, int CourseDays2, int CourseDays3, Degree DegreeProgram) {
    int CourseDays[3] = {CourseDays1, CourseDays2, CourseDays3};

    for (int i = 0; i < classRosterSize; i++) {
        if (classRosterArray[i] == nullptr) {

            if (DegreeProgram == NETWORKING) {
                classRosterArray[i] = new networkStudent(Id, FirstName, LastName, Email, Age, CourseDays, DegreeProgram);
            }
            else if (DegreeProgram == SECURITY) {
                classRosterArray[i] = new securityStudent(Id, FirstName, LastName, Email, Age, CourseDays, DegreeProgram);
            }
            else if (DegreeProgram == SOFTWARE) {
                classRosterArray[i] = new softwareStudent(Id, FirstName, LastName, Email, Age, CourseDays, DegreeProgram);
            }
            else {
                classRosterArray[i] = new Student(Id, FirstName, LastName, Email, Age, CourseDays, DegreeProgram);
            }
            break;
        }
    }
}

//print all data
void Roster::printAll() {
    for (int i = 0; i < classRosterSize; i++) {
        classRosterArray[i]->print();
    }
    cout << "\n";
}

//print students in degree program
void Roster::printByDegreeProgram(int DegreeProgram) {
    for (int i = 0; i < classRosterSize; i++) {
        if (classRosterArray[i]->getDegreeProgram() == DegreeProgram) //possible change to program, not type
             {
            classRosterArray[i]->print();
        }
    }
    cout << "\n";
}

//print average days
void Roster::printAverageCourseDays(string Id) {
    for (int i = 0; i < classRosterSize; i++) {
        if ((*classRosterArray[i]).getId() == Id) {
            int avg = 0;
            avg = ((*classRosterArray[i]).getCourseDays()[0] + (*classRosterArray[i]).getCourseDays()[1]
                   + (*classRosterArray[i]).getCourseDays()[2]) / 3;
            cout << "The average days it took the student with ID Number " << Id << " to finish 3 courses: "
                 << avg << "\n";
        }
    }
    cout << "\n";
}
//print invalid e-mails
void Roster::printInvalidEmails() {
    for (int i = 0; i < classRosterSize; i++) {
        string Email = classRosterArray[i]->getEmail();
        bool isValid = false;

        size_t found = Email.find("@");
        if (found != string::npos) {
            found = Email.find(".");
            if (found != string::npos) {
                found = Email.find(" ");
                if (found == string::npos) {
                    isValid = true;
                }
            }
        }

        if (!isValid) {
            cout << Email << " is not a valid email address \n";
        }
    }


}
//remove student from roster
void Roster::remove(string Id) {
    bool removed = false;
    for (int i = 0; i < classRosterSize; i++) {
        if (classRosterArray[i] != nullptr) {
            if (Id == classRosterArray[i]->getId()) {
                classRosterArray[i] = nullptr;
                removed = true;
            }
        }
    }
    if (!removed) {
        cout << "Error: No student with the ID " << Id << " exists." << "\n";
    }
}


Roster::~Roster()
{

}