#include "question.h"
void Question::setQuestion(string q)
{
    question=q;
}
void Question::setoptionA(string a)
{
    optionA=a;
}
void Question::setoptionB(string b)
{
    optionB=b;
}
void Question::setoptionC(string c)
{
    optionC=c;
}
void Question::setoptionD(string d)
{
    optionD=d;
}
void Question::setcorrectAnswer(char ans)
{
    correctAnswer=ans;
}

void Question::displayquestion()
{
    cout<<"\n"<<question<<endl;

    cout<<"A."<<optionA<<endl;
    cout<<"B."<<optionB<<endl;
    cout<<"C."<<optionC<<endl;
    cout<<"D."<<optionD<<endl;
}

char Question::getcorrectanswer()
{
    return correctAnswer;
}