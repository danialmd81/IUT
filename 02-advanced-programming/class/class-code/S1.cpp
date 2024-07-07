#include <iostream>

using namespace std;

//in this section, we solved the diomond problem.
 class c1
{
public :
    string name;
         c1()
        {
            name = "noName";
        }
};
class c2 :public virtual c1
{

protected:
    int i2;
public:
    c2()
    {
        i2 = 0;
        name="c2";
    }

};
class c3 :public c2
{

protected:
    int i3;
public:
    c3()
    {
        i3 = 0;
        name="c3";
    }
};
class c4 :public virtual c1,public c3
{

private:
    int i4;
public:
    c4()
    {
        i4 = 0;
    }

};


int main()
{
    c1 obj1;
    c2 obj2;
    c3 obj3;
    c4 obj4;
    cout<<obj4.name;
}
