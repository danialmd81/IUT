// extra info on inheritance. at first, we used overriding to override a print function in parent class.
#include <iostream>

using namespace std;

class person
{
protected:
    string name;
    int age;
public:
    person()
    {
        name = "noName";
        age = 0;
    }
    person(string n, int a)
    {
        name = n;
        age = a;
    }
    void print()
    {
        cout << name << " is " << age << " years old.";
    }
};
class student :public person
{
private:
    double avg;
public:
    student(double av)
{
    avg = av;
}
        void print()
        {
            person::print();
            cout << " and his average is : " << avg;
        }
};
//in this section, we solved the diomond problem.
class c1
{
public:
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
    }
};
class c3 :public virtual c1
{
protected:
    int i3;
public:
    c3()
    {
        i3 = 0;
    }
};
class c4 :public c2 , public c3
{
private:
    int i4;
public:
c4()
{
    i4 =4;
}

};
// at last, we used public, protected and private inheritances and how they work.
class s1
{
protected:
    int prot;
private:
    int priv;
public:
    int publ;
    s1()
    {

    }
};
class s2 : public s1 {
public: s2()
{
    prot = 12;
    }
};
class s3 : protected s1 {
public: s3() {}
};

class s4 : private s1 {
public: s4() { }
};
class s5 : public s4 {

};
int main()
{
    // person p1("ali", 20);
    // p1.print();
    // student s1(14.5);
    // s1.print();
	// s2 obj2;
	// obj2.publ;
	// s3 obj3;
	// obj3.publ; //error
	// s4 obj4;
    c4 obj4;
    cout<<obj4.name;

}
