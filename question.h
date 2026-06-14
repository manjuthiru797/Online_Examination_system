#ifndef QUESTION_H
#define QUESTION_H

#include<iostream>
#include<cstring>

using namespace std;

class Question
{
    private:
        string question;
        string optionA;
        string optionB;
        string optionC;
        string optionD;
        char correctAnswer;

    public:
        void setQuestion(string q);
        void setoptionA(string a);
        void setoptionB(string b);
        void setoptionC(string c);
        void setoptionD(string d);
        void setcorrectAnswer(char ans);

        void displayquestion();
        char getcorrectanswer();
};

#endif