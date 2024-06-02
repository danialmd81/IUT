#include<iostream>

using namespace std;

class Object
{
protected:
    string name;
    int number,ID;

public:
    Object()
    {
        set_name();
        set_number();
    };
    ~Object()
    {

    };
    virtual void set_ID()= 0;
    bool operator == (const Object& s)const
    {
        return name == s.name && ID == s.ID;
    }
    bool operator != (const Object& s)const
    {
        return !operator==(s);
    }
    void set_name()
    {
        cout<<"name:";
        cin>>name;
    }
    void show_obj()
    {
        cout<<"name:"<<name<<endl<<"number:"<<number<<endl;
    }
    string get_name()
    {
        return name;
    }
    int get_ID()
    {
        return ID;
    }
    void set_number()
    {
        cout<<"number:";
        cin>>number;
    }
    int get_number()
    {
        return number;
    }
};

void Object::set_ID()
{
    static int id=0;
    ID=id;
    id++;
}
