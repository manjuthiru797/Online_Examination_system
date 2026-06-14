#ifndef EXAM_H
#define EXAM_H

#include<iostream>
using namespace std;

class Exam
{
    private:
        int totalQuestions;
        int marks;
    public:
        void startExam(int studentId);
        void evaluateExam(int score,int studentId);
};

#endif