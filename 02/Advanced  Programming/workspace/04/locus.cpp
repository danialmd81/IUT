#include"point.h"

enum state  {triangle,styloid,unknown};

class locus
{
private:
    int p_num;
    point *p_arr;
    state sta;
public:
    locus()
    {
        p_num=3;
        p_arr=new point[p_num];
        sta=triangle;
        for(int i=0;i<p_num;i++)
        {
            p_arr[i].x=rand()%20-10;
            p_arr[i].y=rand()%20-10;
            for (int j = 0; j < i; j++)
            {
                if(p_arr[j]==p_arr[i])
                {
                    p_arr[i].x=rand()%20-10;
                    p_arr[i].y=rand()%20-10;
                }
            }
        }
    }
    locus(int si)
    {
        if(si>=3)
        {
            p_num=si;
            p_arr=new point [p_num];
            sta=styloid;
            for(int i=0;i<p_num;i++)
            {
                p_arr[i].x=i;
                p_arr[i].y=i*i;
            }
        }
        else
        {
            cout <<"number of point shuld be more than 3."<<endl;
        }
    }
    locus(int si ,point *p)  //warning:if you change elements in *p ,elements in p_arr array change too and revers .
    {
        if(si>=3)
        {
            p_num=si;
            p_arr=new point [p_num];
            p_arr=p;
            sta=unknown;
            for(int i=0;i<p_num;i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if(p_arr[j]==p_arr[i])
                    {
                        cout<<"error beacuse ther is two point that are equal."<<endl;
                    }
                }
            }
        }
        else
        {
            cout <<"number of point shuld be more than 3."<<endl;
        }
    }
    locus(locus &cl)
    {
        p_num=cl.p_num;
        p_arr=new point [p_num];
        sta=cl.sta;
        for(int i=0;i<p_num;i++)
        {
            p_arr[i]=cl.p_arr[i];
        }
    }
    bool is_side(int p1,int p2)
    {
        int a=p_arr[p2].x_coefficent(p_arr[p1]), b=p_arr[p2].y_intercept(p_arr[p1]), location;
        bool flag_all_umder=1,flag_all_above=1,flag_collinear=0;
        for(int i=0;i<p_num;i++)
        {
            if(i==p1||i==p2)
            {
                continue;
            }
            else
            {
                location=p_arr[i].y-a*p_arr[i].x-b;
                if(location>0)
                flag_all_above=0;
                if(location==0)
                flag_collinear=1;
                if(location<0)
                flag_all_umder=0;
            }
        }
        if(flag_all_above)
        return true;
        else if(flag_all_umder)
        return true;
        else
        return false;

    }

    bool convex_check()
    {
        if(sta==triangle)
        {
            if(((p_arr[2].x * p_arr[0].x_coefficent(p_arr[1]))+(p_arr[0].y_intercept(p_arr[1])))==(p_arr[2].y))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if(sta==styloid)
        {
            return true;
        }
        else if(sta==unknown)
        {
            int count=0;
            for(int i=0;i<p_num;i++)
            {
                for(int j=i+1;j<p_num;j++)
                {
                    if(is_side(i,j))
                    {
                        count++;
                    }
                }
            }
            if(count==p_num)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return -1;
        }
    }

    void show_locus()
    {
        for(int i=0;i<p_num;i++)
        {
            p_arr[i].show();
        }
    }

    double locus_perimeter()
    {
        double perimeter=0;
        if(convex_check()&&sta==triangle)
        {
            perimeter=p_arr[1].two_point_distance(p_arr[0]) + p_arr[2].two_point_distance(p_arr[1]) + p_arr[0].two_point_distance(p_arr[2]);
            return perimeter;
        }
        else if(convex_check()&&sta==styloid)
        {
            for(int i=1;i<p_num;i++)
            {
                perimeter=perimeter+p_arr[i].two_point_distance(p_arr[i-1]);
            }
            perimeter=perimeter+p_arr[0].two_point_distance(p_arr[p_num-1]);
            return perimeter;
        }
        else if(convex_check()&&sta==unknown)
        {
            for(int i=0;i<p_num;i++)
            {
                for(int j=i+1;j<p_num;j++)
                {
                    if(is_side(i,j))
                    {
                        perimeter+=p_arr[j].two_point_distance(p_arr[i]);
                    }
                }
            }
            return perimeter;
        }
        else
        {
            cout<<"the locus is not convex."<<endl;
            return -1;
        }
    }

    double triangle_area(int a, int b, int c)
    {
        double area;
        area=abs(p_arr[a].x*(p_arr[b].y-p_arr[c].y)+p_arr[b].x*(p_arr[c].y-p_arr[a].y)+p_arr[c].x*(p_arr[a].y-p_arr[b].y));
        return area/2;
    }

    double locus_area()
    {
        double area=0;
        if(convex_check()&&sta==triangle)
        {
            area=(p_arr[0].x*(p_arr[1].y-p_arr[2].y) + p_arr[1].x*(p_arr[2].y-p_arr[0].y) + p_arr[2].x*(p_arr[0].y-p_arr[1].y))/2;
            return abs(area);
        }
        else if(convex_check()&&sta==styloid)  /* i get this formule fromethis site:
        https://www.wikihowfarsi.com/
        %D9%85%D8%B3%D8%A7%D8%AD%D8%AA-%DB%8C%DA%A9-%DA%86%D9%86%D8%AF-%D8%B6%D9%84%D8%B9%DB%8
        C-%D8%B1%D8%A7-%D9%85%D8%AD%D8%A7%D8%B3%D8%A8%D9%87-%DA%A9%D9%86%DB%8C%D9%85*/
        {
            for (int i=0;i<p_num-1;i++)
            {
                area+=(p_arr[i].x*p_arr[i+1].y)-(p_arr[i].y*p_arr[i+1].x);
            }
            return area/2;
        }
        else if(convex_check()&&sta==unknown)
        {
            int c=0;
            for(int i=1;i<p_num;i++)
            {
                if(is_side(0,i))
                {
                    for(int j=i+1;j<p_num;j++)
                    {
                        if(is_side(i,j))
                        {
                            area+=triangle_area(0, i, j);
                            c++;
                        }
                    }
                }
            }
            return area;
        }
        else
        {
            cout<<"the locus is not convex."<<endl;
            return -1;
        }
    }

    ~locus()
    {
        delete []p_arr;
        cout<<"memmory freed."<<endl;
    }
};
