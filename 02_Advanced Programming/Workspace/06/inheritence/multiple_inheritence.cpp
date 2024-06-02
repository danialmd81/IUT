#include<iostream>

using namespace std;

class Teacher
{
protected:
    int salary;
public:
    Teacher(int s)
    {
        salary=s;
    };
    ~Teacher()
    {
        cout<<"deconstructor\n";
    };
};

class Student
{
protected:
    string gpa;
public:
    Student(string g)
    {
        gpa=g;
    };
    ~Student()
    {
        cout<<"deconstructor\n";
    };
};

class Teacher_Assistant:public Student,public Teacher
{
private:
    bool Has_Yekta_Access;
public:
    Teacher_Assistant(int s,string g,bool h):Student(g),Teacher(s)
    {
        Has_Yekta_Access=h;
    };
    ~Teacher_Assistant()
    {
        cout<<"deconstructor\n";
    };
};
