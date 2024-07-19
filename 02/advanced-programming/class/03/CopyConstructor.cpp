// goal: working with copy constructor in c++
// every c++ class has a copy constructor built for making copies of a vriabla possible
// whenever we try to copy an object from a certain class into another object of that class,
// the copy constructor function will be called and do the job for us.
// by default like constructor and destructor, there is a default function for copy constructor too
// if we donot declare a copy constructor, the default will be used whenever needed.
// copy constructor will be called in 3 ocasions: 1: whenever a = operator is used while declaring an object from sameclass
// 2-whenever we call the object by value in a function 3: whenever a function returns an object of that type

#include <iostream>
using namespace std;
class vector
{
public:

    vector(vector& v)  //copy constructor will have an object of the same class as input
    {
        size = v.size;
        elem = new int[v.size];
        for (int i = 0; i < v.size; i++)
        {
            elem[i] = 8;
        }
    }
    vector(int s) // constructor
    {
        size = s;
        elem = new int[s];
        for (int i = 0; i < s; i++)
        {
            elem[i] = 0;
        }
    }
    int get_size()
    {
        return this->size; // this referes to the object that the function is called by it
    }
    void set_size(int data)
    {
        size = data;
    }
    int get_elem(int index)
    {
        return elem[index];
    }
    void set_elem(int index, int data)
    {
        elem[index] = data;
    }
private:
    int size;
    int* elem;
};
int main()
{
    vector v1(5);
    vector v2(v1); // = vector v2 = v1;
    //vector v2(14);
    v1 = v2; // the copy constructor will NOT be called here
    v1.set_size(12);
    v1.set_elem(3, 12);
    cout << "v1 size = " << v1.get_size() << endl;
    cout << "v2 size = " << v2.get_size() << endl;
    cout << "v1 contains : " << endl;
    for (int i = 0; i < v1.get_size(); i++) {
        cout << v1.get_elem(i) << " ";
    }
    cout << endl;
    cout << "v2 contains : " << endl;
    for (int i = 0; i < v2.get_size(); i++) {
        cout << v2.get_elem(i) << " ";
    }
}
