#include<iostream>
#include "student.h"
#include "admin.h"

using namespace std;
int main()
{
    int choice;

    do
    {
        cout<<"-----------------------------------\n";
        cout<<"       Online Examination System\n";
        cout<<"-----------------------------------\n";
        cout<<"1.Admin Login\n";
        cout<<"2.Student Registration\n";
        cout<<"3.Student Login\n";
        cout<<"4.Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                Admin admin;
                admin.loginAdmin();
                break;
            }    
            case 2:
            {
                student Student;
                Student.registerStudent();
                break;
            }
            case 3:
            {
                student Stu;
                Stu.loginStudent();
                break;
            }
            case 4:
            {
                cout<<"Thank you! Exiting\n";
            }
            default:
            {
                cout<<"\nInvalid choice\n";
            }
        }
    }while(choice!=4);
}