#include "admin.h"
#include<fstream>
#include<cstring>

void Admin::loginAdmin()
{
    string username;
    string password;

    cout<<"\n---------Admin Login----------\n";
    cout<<"Username: ";
    cin>>username;

    cout<<"Password : ";
    cin>>password;

    if(username=="admin" && password=="admin123")
    {
        cout<<"\nLogin Successful!\n";
        int choice;

        do
        {
            cout<<"\n------------Admin Menu-------------\n";
            cout<<"1.Add Question\n";
            cout<<"2.View Results\n";
            cout<<"3.Logout\n";
            cout<<"Enter Choice : ";
            cin>>choice;

            switch(choice)
            {
                case 1:
                    addQuestion();
                    break;
                case 2:
                    viewResults();
                    break;
                case 3:
                    cout<<"\nLogged Out Successfully\n";
                    break;
                default:
                    cout<<"\nInvalid Choice\n";
            }
        }while(choice!=3);
    }
    else
    {
        cout<<"\nInvalid Username or Password\n";
    }
}

void Admin::addQuestion()
{
    ofstream fout("questions.txt",ios::app);
    if(!fout)
    {
        cout<<"\nUnable to open questions.txt\n";
        return;
    }

    string question;
    string opA;
    string opB;
    string opC;
    string opD;
    char answer;

    cin.ignore();

    cout<<"\nEnter Question: ";
    getline(cin,question);

    cout<<"Option A: ";
    getline(cin,opA);

    cout<<"Option B :";
    getline(cin, opB);

    cout << "Option C : ";
    getline(cin, opC);

    cout << "Option D : ";
    getline(cin, opD);

    cout << "Correct Answer : ";
    cin >> answer;

    if(answer >='a' && answer <='z')
    {
        answer=answer-32;
    }

    fout<<question<<"|"<<opA<<"|"<<opB<<"|"<<opC<<"|"<<opD<<"|"<<answer<<endl;
    fout.close();
    cout<<"\nQuestion Added Successfully!\n";
}

void Admin::viewResults()
{
    ifstream fin("results.txt");

    if(!fin)
    {
        cout<<"\nUnable to open results.txt\n";
        return;
    }
    int studentid;
    int marks;
    float percentage;
    string result;

    cout<<"\n--------All Results------------\n";
    while(fin>>studentid>>marks>>percentage>>result)
    {
        cout<<"\nStudent ID: "<<studentid<<endl;
        cout<<"Marks       : "<<marks<<endl;
        cout<<"Percentage  : "<<percentage<<"%"<<endl;
        cout<<"Result      : "<<result<<endl;

        cout<<"-----------------------------\n";
    }
    fin.close();
}