#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<cstring>

using namespace std;

class student
{
    int studentId;
    string name;
    string password;

    public:
        void registerStudent();
        void loginStudent();
        void takeExam();
        void viewResult();
};

#endif