#include<iostream>

using namespace std;

class person
{
protected:
string name,phone,email;
public:
    person(string n,string p,string e)
    {
        name=n;
        phone=p;
        email=e;
    }
    ~person()
    {
        cout<<"deconstructor\n";
    }
};

class student:public person
{
private:
    string student_number;
    int average_mark;
public:
    student(string stu,int m,string n,string p,string e):person(n,p,e)
    {
        student_number=stu;
        average_mark=m;
    };
    ~student()
    {
         cout<<"deconstructor\n";
    };
    void get_data()
    {
        cout<<student_number<<"  "<<average_mark<<"  "<<name<<"  "<<phone<<"  "<<email
        <<endl;
    };
};





int main()
{
    student a("1",14,"danial","09136049474","danial");
    a.get_data();
}