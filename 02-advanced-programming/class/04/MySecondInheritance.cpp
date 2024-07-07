// extra info on inheritance. at first, we used overriding to override a print function in parent class.
#include <iostream>
using namespace std;
class person {
protected:
    string name;
    int age;
public:
    person() { name = "noName"; age = 0; }
    person(string n, int a) { name = n; age = a; }
    void print() {
        cout << name << " is " << age << " years old.";
    }
};
class student :public person {
private: double avg; 
public: student(double av) { avg = av; }
      void print() {
          person::print();
             cout << " and his average is : " << avg;
      }
};
//in this section, we solved the diomond problem.
class c1 {
public: string name;
	  c1() { name = "noName"; }
};
class c2 :virtual public c1 {
protected: int i2;
public: c2() { i2 = 0; }
};
class c3 :virtual public c1 {
protected: int i3;
public: c3() { i3 = 0; }
};
class c4 :public c2, public c3 {
private: int i4;
public: c4(int i) { i4 = i; c2::name = "c2";
	  c3::name = "c3"; }
};
// at last, we used public, protected and private inheritances and how they work.
class c1 {
protected: int prot;
private: int priv;
public: int publ; c1(){}
};
class c2 : public c1 {
public: c2() { prot = 12; }  
};
class c3 : protected c1 {
public: c3() {}
};

class c4 : private c1 {
public: c4() { }
};
class c5 : public c4 {

};
int main()
{
    person p1("ali", 20);
    p1.print();
    student s1(14.5);
    s1.print();
	c2 obj2;
	obj2.publ;
	c3 obj3;
	obj3.publ; //error
	c4 obj4;
	
}

