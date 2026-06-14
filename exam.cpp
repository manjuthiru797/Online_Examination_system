#include "exam.h"
#include "question.h"
#include "student.h"

#include<fstream>
#include<sstream>

void Exam::startExam(int studentId)
{
    ifstream fin("questions.txt");
    if(!fin)
    {
        cout<<"\nUnable to open questions\n";
        return;
    }
    string line;
    int score=0;
    totalQuestions=0;

    while(getline(fin,line))
    {
        stringstream ss(line);

        string question;
        string opA,opB,opC,opD;
        string correct;

        getline(ss,question,'|');
        getline(ss,opA,'|');
        getline(ss,opB,'|');
        getline(ss,opC,'|');
        getline(ss,opD,'|');
        getline(ss,correct);

        Question q;

        q.setQuestion(question);
        q.setoptionA(opA);
        q.setoptionB(opB);
        q.setoptionC(opC);
        q.setoptionD(opD);
        q.setcorrectAnswer(correct[0]);

        totalQuestions++;

        cout<<"\nQuestion "<<totalQuestions<<endl;

        q.displayquestion();

        char studentans;

        cout<<"Enter Answer:";
        cin>>studentans;

        if(studentans>='a' && studentans<='z')
        {
            studentans=studentans-32;
        }
        if(studentans==q.getcorrectanswer())
        {
            score++;
        }
    }

    fin.close();
    evaluateExam(score,studentId);
}

void Exam::evaluateExam(int score,int studentId)
{
    marks=score;
    float percentage=(marks*100.0)/totalQuestions;

    cout<<"\n----------Result------------\n";
    cout<<"Total Questions : "<<totalQuestions<<endl;
    cout<<"Marks Obtained : "<<marks<<endl;
    cout<<"Percentage : "<<percentage<<"%"<<endl;

    string result;
    if(percentage>=40)
    {
        result="Pass";
    }
    else
    {
        result="Fail";
    }

    cout<<"Result"<<result<<endl;

    ofstream fout("results.txt",ios::app);

    if(!fout)
    {
        cout<<"\nUnable to open results.txt\n";
        return;
    }
    fout<<studentId<<" "<<marks<<" "<<percentage<<" "<<result<<endl;
    fout.close();
}