#include "student.h"
#include <fstream>
#include "exam.h"
void student::registerStudent()
{
    ofstream fout("students.txt",ios::app);

    cout<<"\n-------Student Registration------\n";

    cout<<"Enter Student ID: ";
    cin>>studentId;

    cout<<"Enter Name:";
    cin>>name;

    cout<<"Create Password:";
    cin>>password;

    fout<<studentId<<" "<<name<<" "<<password<<endl;

    fout.close();

    cout<<"\nRegistration Successful!\n";
}

void student::loginStudent()
{
    int id;
    string password;

    cout<<"\n-------Student Login-------\n";

    cout<<"Enter Student ID:";
    cin>>id;

    cout<<"Enter Password:";
    cin>>password;

    ifstream fin("students.txt");

    int fileid;
    string filename;
    string filepass;

    int found=0;

    while(fin>>fileid>>filename>>filepass)
    {
        if(id==fileid && password==filepass)
        {
            studentId=fileid;
            found=1;
            break;
        }
    }

    fin.close();

    if(found)
    {
        cout<<"\nLogin Successful\n";

        int choice;

        do
        {
            cout<<"\n ---------Student Menu----------\n";
            cout<<"1.start Exam\n";
            cout<<"2.View Result\n";
            cout<<"3.Logout\n";
            cout<<"enter Choice : ";
            cin>>choice;

            switch(choice)
            {
                case 1:
                    takeExam();
                    break;
                case 2:
                    viewResult();
                    break;
                case 3:
                    cout<<"\nLogged out Successfully\n";
                    break;
                default:
                    cout<<"\nInvalid Choice\n";
            }
        }while(choice!=3);
    }
    else
    {
        cout<<"\nInvalid ID or Password\n";
    }
}


void student::takeExam()
{
    Exam exam;
    exam.startExam(studentId);
}

void student::viewResult()
{
    ifstream fin("results.txt");

    int id;
    int marks;
    float percentage;
    string result;

    int latestMarks;
    float latestPercentage;
    string latestResult;

    bool found = false;

    while(fin >> id >> marks >> percentage >> result)
    {
        if(id == studentId)
        {
            latestMarks = marks;
            latestPercentage = percentage;
            latestResult = result;

            found = true;
        }
    }

    fin.close();

    if(found)
    {
        cout << "\n------Your Result--------\n";
        cout << "Student ID: " << studentId << endl;
        cout << "Marks     : " << latestMarks << endl;
        cout << "Percentage: " << latestPercentage << "%" << endl;
        cout << "Result    : " << latestResult << endl;
    }
    else
    {
        cout << "\nNo Result Found\n";
    }
}

