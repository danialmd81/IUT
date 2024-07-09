#include<iostream>
#include<list>
#include"Lessons.h"
#include"Person.h"

using namespace std;

class Teacher:virtual public Person
{
protected:
    int Teacher_number,recruitment_year,salary;
    string degree;
    bool is_supervisor;
    list<Lessons> t_lessons;

public:
    Teacher():Person()
    {
        set_ID();
        set_Teacher_number_number();
        set_recruitment_year();
        set_salary();
        set_degree();
        set_is_supervisor();
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
    ~Teacher()
    {

    };
    void set_ID()
    {
        static int id=0;
        ID=id;
        id++;
    }
    bool operator == (const Teacher& s) const
    {
        return name == s.name && ID == s.ID && Teacher_number==s.Teacher_number;
    }
    bool operator != (const Teacher& s) const
    {
        return !operator==(s);
    }
    void show()
    {
        show_person();
        cout<<"ID:"<<ID<<endl<<"Teacher_number:"<<Teacher_number<<endl
        <<"recruitment_year:"<<recruitment_year<<endl<<"salary:"<<salary<<endl
        <<"degree:"<<degree<<endl;
        is_supervisor?cout<<"is_supervisor is on.\n":cout<<"is_supervisor is off.\n";
        for(auto &i : t_lessons)
        {
            cout<<"lesson:"<<endl;
            i.show_lessons();
        }
    }
    bool check_teacher_number(int num)
    {
        return Teacher_number==num;
    }
    void set_Teacher_number_number()
    {
        cout<<"Teacher_number:";
        cin>>Teacher_number;
    }
    int get_Teacher_number()
    {
        return Teacher_number;
    }
    void set_recruitment_year()
    {
        cout<<"recruitment_year:";
        cin>>recruitment_year;
    }
    int get_recruitment_year()
    {
        return recruitment_year;
    }
    void set_salary()
    {
        cout<<"salary:";
        cin>>salary;
    }
    int get_salary()
    {
        return salary;
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
    void set_is_supervisor()
    {
        cout<<"is_supervisor(1or0):";
        int a;
        cin>>a;
        a?is_supervisor_on():is_supervisor_off();
    }
    void is_supervisor_on()
    {
        is_supervisor=1;
    }
    void is_supervisor_off()
    {
        is_supervisor=0;
    }
    void add_lessons(const Lessons &add)
    {
        t_lessons.push_back(add);
        cout<<"lesson is added.\n";
    }
    void delete_lessoms(const Lessons &del)
    {
        t_lessons.remove(del);
        cout<<"lesson is removed.\n";
    }
};
