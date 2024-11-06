// in this section, we talked about how inheritance works and how we can use it.
// one important point we discussed was about parent and child both have the same name.
#include <iostream>
using namespace std;
class person {
protected:
    string name;
    int age;
public:
    person() {
        name = "noName";
        age = 0;
    }
    person(string name, int age) {
        this->age = age;
        this->name = name;
    }
    string get_name() { return name; }
    int get_age() { return age; }
    void set_name(string data) { name = data; }
};
class course {
protected:
    string Cname;
    int year;
public:
    course() { Cname = " no course name"; year = 0; }
    course(string cname, int year) {
        this->Cname = cname;
        this->year = year;
    }
};
class student: public person, public course {
private:
    double avg;
public:
    student( string name1, int age1,string cname1, int year1 ,double avg1):person(name1,age1),course(cname1,year1) {
        this->avg = avg1;
    }
    double get_avg() { return avg; }
    string get_n() { return this->name; }
    void set_n(string data) { person::name = data; }
};


int main()
{
    student s1("ali", 18, 14.5);
    
    cout<< "student name is: " << s1.get_n() << " studnt age is : "
        << s1.get_age() << " student avg is : " << s1.get_avg();
    s1.set_name("parent's name");
    s1.set_n("child's name");
    cout << s1.get_name() << " " << s1.get_n();
}

