#include<iostream>

using namespace std;

class Employee
{
protected:
    string employee_id;
    int salary;
public:
    Employee(string e,int s)
    {
        employee_id=e;
        salary=s;
    };
    ~Employee()
    {
        cout<<"deconstructor\n";
    };
};

class Manager:public Employee
{
private:
    string department;
public:
    Manager(string d,string e,int s):Employee(e,s)
    {
        department=d;
    };
    ~Manager()
    {
        cout<<"deconstructor\n";
    };
};

class Salesperson:public Employee
{
private:
    string commission;
public:
    Salesperson(string c,string e,int s):Employee(e,s)
    {
        commission=c;
    };
    ~Salesperson()
    {
        cout<<"deconstructor\n";
    };
};

int main()
{
    
}
