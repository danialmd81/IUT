#include<iostream>
#include"Object.h"

using namespace std;

class Lessons:public Object
{
protected:
    int unit,e_year,e_mounth,e_day,e_hour,e_minute;
    string e_place;
public:
    Lessons():Object()
    {
        set_unit();
        set_e_year();
        set_e_mounth();
        set_e_day();
        set_e_hour();
        set_e_minute();
        set_e_place();
    };
    ~Lessons()
    {

    };
    void set_ID()
    {
        static int id=0;
        ID=id;
        id++;
    }
    bool operator == (const Lessons& s)const
    {
        return name == s.name && ID == s.ID && unit==s.unit;
    }
    bool operator != (const Lessons& s)const
    {
        return !operator==(s);
    }
    void show_lessons()
    {
        show_obj();
        cout<<"unit:"<<unit<<endl<<"exam date:"<<e_year<<"/"<<e_mounth<<"/"<<e_day<<endl
        <<"exam time:"<<e_hour<<":"<<e_minute<<endl<<"exam place:"<<e_place<<endl;
    }
    void set_unit()
    {
        cout<<"unit:";
        cin>>unit;
    }
    int get_unit()
    {
        return unit;
    }
    void set_e_year()
    {
        cout<<"e_year:";
        cin>>e_year;
    }
    int get_e_year()
    {
        return e_year;
    }
    void set_e_mounth()
    {
        cout<<"e_mounth:";
        cin>>e_mounth;
    }
    int get_e_mounth()
    {
        return e_mounth;
    }
    void set_e_day()
    {
        cout<<"e_day:";
        cin>>e_day;
    }
    int get_e_day()
    {
        return e_day;
    }
    void set_e_hour()
    {
        cout<<"e_hour:";
        cin>>e_hour;
    }
    int get_e_hour()
    {
        return e_hour;
    }
    void set_e_minute()
    {
        cout<<"e_minute:";
        cin>>e_minute;
    }
    int get_e_minute()
    {
        return e_minute;
    }
    void set_e_place()
    {
        cout<<"e_place:";
        cin>>e_place;
    }
    string get_e_place()
    {
        return e_place;
    }
};
