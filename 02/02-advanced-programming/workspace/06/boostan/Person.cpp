#include<iostream>

using namespace std;

enum emonths{فروردین=1,اردیبشت,خرداد,تیر,مرداد,شهریور,مهر,آبان,آذر,دی,بهمن,اسفند};

class Person
{
protected:
    string name,family_name;
    int ID,national_code,year,day,month;
    emonths months;
    bool deleted;
public:
    Person()
    {
        set_name();
        set_family_name();
        set_national_code();
        set_day();
        set_month();
        set_year();
    };
    ~Person()
    {

    };
    virtual void set_ID() = 0;
    bool operator == (const Person& s) const
    {
        return name == s.name && ID == s.ID;
    }
    bool operator != (const Person& s) const
    {
        return !operator==(s);
    }
    void show_person()
    {
        cout<<"name:"<<name<<endl<<"family_name:"<<family_name<<endl
        <<"national_code:"<<get_national_code()<<endl
        <<"Birh Date:"<<year<<"/"<<month<<"/"<<day<<endl;
    }
    int get_ID()
    {
        return ID;
    }
    void set_national_code()
    {
        cout<<"national_code:";
        cin>>national_code;
    }
    int get_national_code()
    {
        return national_code;
    }
    void set_year()
    {
        cout<<"year:";
        cin>>year;
    }
    int get_year()
    {
        return year;
    }
    void set_month()
    {
        cout<<"month:";
        cin>>month;
        months=static_cast<emonths>(month);
    }
    int get_mounth()
    {
        return month;
    }
    void set_day()
    {
        cout<<"day:";
        cin>>day;
    }
    int get_day()
    {
        return day;
    }
    void set_name()
    {
        cout<<"name:";
        cin>>name;
    }
    string get_name()
    {
        return name;
    }
    void set_family_name()
    {
        cout<<"family_name:";
        cin>>family_name;
    }
    string get_family_name()
    {
        return family_name;
    }
    bool get_soft_delete()
    {
        return deleted;
    }
    void remove()
    {
        deleted=1;
        cout<<"object is deleted.\n";
    }
    void unremove()
    {
        deleted=0;
        cout<<"object is not deleted.\n";
    }
};

void Person:: set_ID()
{
    static int id=0;
    ID=id;
    id++;
}
