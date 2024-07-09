#include<iostream>
#include<algorithm>

using namespace std;

class Time
{
private:
    int hour=0,min=0;
public:

    Time(int h)
    {
        set_hour(h);
        set_min(0);
    }
    Time(int h,int m)
    {
        set_hour(h);
        set_min(m);
    }
    int get_hour()
    {
        return hour;
    }
    void set_hour(int h)
    {
        if(h>23||h<0)
        {
            cout<<"wrong input";
            exit(0);
        }
        else
        {
            hour=h;
        }
    }
        int get_min()
    {
        return min;
    }
    void set_min(int m)
    {
        if(m>59||m<0)
        {
            cout<<"wrong input";
            exit(0);
        }
        else
        {
            min=m;
        }
    }
    string tell_time()
    {
        string time;
        if(hour==0&&min!=0)
        {
            time="morning";
        }
        if(hour==0&&min==0)
        {
            time="night";
        }
        if(hour<12&&hour>0)
        {
            time="morning";
        }
        if(hour==12&&min!=0)
        {
            time="after noon";
        }
        if(hour==12&&min==0)
        {
            time="noon";
        }
        if(hour>12&&hour<17)
        {
            time="after noon";
        }
        if(hour>=17&&hour<20)
        {
            time="evening";
        }
        if(hour>=20&&hour<24)
        {
            time="night";
        }
        return time;
    }
    int compare(Time a)
    {
        if(a.hour==hour&&a.min==min)
        {
            return 1;
        }
        else if(a.hour>hour)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    Time a(23,59),b(20);

    cout<<a.tell_time()<<endl<<b.tell_time();
}