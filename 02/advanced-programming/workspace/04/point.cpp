#include<iostream>
#include<time.h>
#include<cmath>
#include<stack>
#include<stdlib.h>
#include<limits>

using namespace std;

class point
{
private:
    int x,y;
public:
    point()
    {
        x=rand()%201-100;
        y=rand()%201-100;
    }
    point(int l)
    {
        x=l;
        y=rand()%201-100;
    }
    point(int l,int w)
    {
        x=l;
        y=w;
    }
    point(point &a)
    {
        x=a.x;
        y=a.y;
    }
    ~point()
    {
        cout<<"point destruction."<<endl;
    }
    void show()
    {
        cout<<'('<<x<<','<<y<<')'<<endl;
    }
    bool operator==(point c)
    {
        if(c.x==x&&c.y==y)
        return true;
        else
        return false;
    }
    double two_point_distance(point &p1)
    {
        double distance;
        distance=sqrt((x-p1.x)*(x-p1.x)+(y-p1.y)*(y-p1.y));
        return distance;
    }
    int x_coefficent(point &p1)
    {
        int inf=numeric_limits<int>::infinity();
        return (x-p1.x!=0)?(y-p1.y)/(x-p1.x):1533;
    }
    int y_intercept(point &p1)
    {
        return (y - (x * x_coefficent(p1)));
    }
    friend class locus;

};
