#include<iostream>
#include<list>
#include"Lessons.h"
#include"Person.h"


using namespace std;

class Student:public virtual Person
{
protected:
    int Student_number,year_of_student,fee;
    string degree,supervisor;
    bool to_pay_fee;
    list<Lessons> s_lessons;

public:
    Student():Person()
    {
        set_ID();
        set_Student_number();
        set_year_of_student();
        set_to_pay_fee();
        if(to_pay_fee)
        set_fee();
        set_degree();
        set_supervisor();
        string input;
        while(1)
        {
            cout<<"lessons:"<<endl
            <<"1_add"<<endl<<"2_delete"<<endl<<"$_return"<<endl;
            cin>>input;
            if(input=="1")
            {
                Lessons add;
                add_lessons(add);
            }
            if(input=="2")
            {
                Lessons del;
                delete_lessoms(del);
            }
            if(input=="$")
            {
                break;
            }
        }
    };
    ~Student()
    {

    };
    void set_ID()
    {
        static int id=0;
        ID=id;
        id++;
    }
    bool operator == (const Student& s) const
    {
        return name == s.name && ID == s.ID && Student_number==s.Student_number;
    }
    bool operator != (const Student& s) const
    {
        return !operator==(s);
    }
    void show()
    {
        show_person();
        cout<<"ID:"<<ID<<endl<<"Student_number:"<<Student_number<<endl
        <<"year_of_student:"<<year_of_student<<endl<<"fee:"<<fee<<endl<<"degree:"<<degree<<endl
        <<"supervisor:"<<supervisor<<endl;
        to_pay_fee?cout<<"to_pay_fee is on.\n":cout<<"to_pay_fee is off.\n";
        for(auto &i : s_lessons)
        {
            cout<<"lesson:"<<endl;
            i.show_lessons();
        }
    }
    void set_Student_number()
    {
        cout<<"Student_number:";
        cin>>Student_number;
    }
    int get_Student_number()
    {
        return Student_number;
    }
    void set_year_of_student()
    {
        cout<<"year_of_student:";
        cin>>year_of_student;
    }
    int get_year_of_student()
    {
        return year_of_student;
    }
    void set_fee()
    {
        cout<<"fee:";
        cin>>fee;
    }
    int get_fee()
    {
        return fee;
    }
    void set_degree()
    {
        cout<<"degree:";
        cin>>degree;
    }
    string get_degree()
    {
        return degree;
    }
    void set_supervisor()
    {
        cout<<"supervisor:";
        cin>>supervisor;
    }
    string get_supervisor()
    {
        return supervisor;
    }
    void set_to_pay_fee()
    {
        cout<<"to_pay_fee(1or0):";
        int a;
        cin>>a;
        a?to_pay_fee_on():to_pay_fee_off();
    }
    void to_pay_fee_on()
    {
        to_pay_fee=1;
        cout<<"to_pay_fee is on.\n";
    }
    void to_pay_fee_off()
    {
        to_pay_fee=0;
        cout<<"to_pay_fee is off.\n";
    }
    void add_lessons(const Lessons &add)
    {
        s_lessons.push_back(add);
        cout<<"lesson is added.\n";
    }
    void delete_lessoms(const Lessons &del)
    {
        s_lessons.remove(del);
        cout<<"lesson is removed\n";
    }
};
