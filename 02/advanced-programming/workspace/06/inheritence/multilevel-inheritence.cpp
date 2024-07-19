#include<iostream>

using namespace std;

class vehicle
{
protected:
    int Fuel_Capacity;
public:
    vehicle(int f)
    {
        Fuel_Capacity=f;
    };
    ~vehicle()
    {
        cout<<"deconstructor\n";
    };
};

class car:public vehicle
{
protected:
    int Number_Of_Wheels;
public:
    car(int f,int n):vehicle(f)
    {
        Number_Of_Wheels=n;
    };
    ~car()
    {
        cout<<"deconstructor\n";
    };
};

class sportcar:public car
{
private:
    int Top_Speed;
public:
    sportcar(int f,int n, int t):car(f,n)
    {
        Top_Speed=t;
    };
    ~sportcar()
    {
        cout<<"deconstructor\n";
    };
};






int main()
{

}