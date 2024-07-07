#include<iostream>
#include<algorithm>


using namespace std;

class Rational
{
private:
    int soorat,makhraj;
public:
    Rational(int soor, int makh)
    {
        soorat=soor;
        makhraj=makh;
    };
    Rational Subtract(Rational another)
    {
        int out_soorat;
        int out_makhraj;
        if(makhraj!=another.makhraj)
        {
            out_soorat=soorat*another.makhraj-another.soorat*makhraj;
            out_makhraj=makhraj*another.makhraj;
        }
        else
        {
            out_soorat=soorat-another.soorat;
            out_makhraj=makhraj;
        }
        Rational out(out_soorat,out_makhraj);
        out.GCD();
        return out;
    }
    void GCD()
    {
        int gcd=__gcd(soorat,makhraj);
        soorat/=gcd;
        makhraj/=gcd;
    }
    int get_soorat()
    {
        return soorat;
    }
    void set_soorat(int soo)
    {
        soorat=soo;
    }
    int get_makhraj()
    {
        return makhraj;
    }
    void set_makhraj(int mak)
    {
        makhraj=mak;
    }
    void show()
    {
        int flag=1;
        if(soorat<0)
        {
            flag*=-1;
            soorat*=-1;
        }
        if(makhraj<0)
        {
            flag*=-1;
            makhraj*=-1;
        }
        soorat*=flag;
        cout<<soorat<<'/'<<makhraj<<endl;
    }
};




int main()
{
    int a,b,c,d;
    scanf("%d/%d",&a,&b);
    scanf("%d/%d",&c,&d);
    Rational obj(a,b);
    Rational obj1(c,d);
    // obj.show();
    // obj1.show();
    Rational aa=obj.Subtract(obj1);
    aa.show();
}