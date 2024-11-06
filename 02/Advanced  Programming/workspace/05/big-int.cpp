#include <iostream>
#include <ostream>
#include <istream>
#include <string.h>
#include <cstring>
#include <cmath>

using namespace std;

class BigInt
{
private:
    int size;
    char *num;
public:
    BigInt()
    {
        size=0;
        num=new char{0};
        // cout << "Constructor 1 is called."<< endl;
    }

    BigInt(int a)
    {
        size= a ;
        num= new char [a+1] {0};
        // cout << "Constructor 2 is called."<< endl;
    }

    BigInt(int a,const char* b)
    {
        size=a;
        num=new char [a+1];
        strcpy(num,b);
        // cout << "Constructor 2 is called."<< endl;
    }

    //use constructor in copy constructor.
    BigInt(const BigInt &cop):BigInt(cop.size , (cop.num))
    {
        // cout<< "Copy Constructor is called."<< endl;
    }
        ~BigInt()
    {
        delete[] num;
    }
/////////////////////////////////////////////////////////////////////////
    void get_data()
    {
        cout<<size<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<num[i];
        }
        cout<<endl;
    }
////////////////////////////////////////////////////////////////////////
    BigInt operator+(const BigInt b)
    {
        char a=0;
        BigInt var1(size),var2(b.size);
        for(int i=size-1,j=0;i>=0;i--,j++)
            {
                var1.num[j]=num[i]-'0';
            }
            for(int i=b.size-1,j=0;i>=0;i--,j++)
            {
                var2.num[j]=b.num[i]-'0';
            }

        if(var1.size>=var2.size)
        {
            BigInt res(var1.size+1,var1.num);
            for(int i=0;i<var2.size;i++)
            {
                if(int(var1.num[i] + var2.num[i])<10)
                {
                    res.num[i]=var1.num[i] + var2.num[i];
                }
                else
                {
                    res.num[i]=int(var1.num[i] + var2.num[i])%10;
                    a=int(var1.num[i] + var2.num[i])/10;
                    var1.num[i+1]+=a;
                }
            }
            for(int i=res.size-1;i>0;i--)
            {
                if(res.num[i]!=0)
                {
                    break;
                }
                res.size--;
            }
            BigInt ans(res.size);
            for(int i=res.size-1,j=0;i>=0;i--,j++)
            {
                ans.num[j]=res.num[i]+'0';
            }
            return ans;
        }
        else
        {
            BigInt res(var2.size,var2.num);
            for(int i=0;i<var1.size;i++)
            {
                if(int(var1.num[i] + var2.num[i])<10)
                {
                    res.num[i]=var1.num[i] + var2.num[i];
                }
                else
                {
                    a=int(var1.num[i] + var2.num[i])/10;
                    res.num[i]=int(var1.num[i] + var2.num[i])%10;
                    var2.num[i+1]+=a;
                }
            }
            for(int i=res.size-1;i>0;i--)
            {
                if(res.num[i]!=0)
                {
                    break;
                }
                res.size--;
            }
            BigInt ans(res.size);
            for(int i=res.size-1,j=0;i>=0;i--,j++)
            {
                ans.num[j]=res.num[i]+'0';
            }
            return ans;
        }
    }
////////////////////////////////////////////////////////////
    BigInt operator+(unsigned long long int bint)
    {
        BigInt b(int(log10(bint))+1 , to_string(bint).c_str());
        BigInt res((*this)+b);
        return res;
    }
//////////////////////////////////////////////////////////////////
    BigInt operator-(const BigInt b)
    {
        if(size>b.size)
        {
            BigInt var1(size),var2(size);
            for(int i=size-1,j=0;i>=0;i--,j++)
            {
                var1.num[j]=num[i]-'0';
            }
            for(int i=b.size-1,j=0;i>=0;i--,j++)
            {
                var2.num[j]=b.num[i]-'0';
            }
            BigInt res(var1);
            for(int i=0;i<var2.size;i++)
            {
                if(var1.num[i] >= var2.num[i])
                {
                    res.num[i]=var1.num[i] - var2.num[i];
                }
                else
                {
                    res.num[i+1]=var1.num[i+1]-1;
                    res.num[i]=(var1.num[i] + 10 - var2.num[i])%10;
                }
            }
            for(int i=res.size-1;i>0;i--)
            {
                if(res.num[i]!=0)
                {
                    break;
                }
                res.size--;
            }
            BigInt ans(res.size);
            for(int i=res.size-1,j=0;i>=0;i--,j++)
            {
                ans.num[j]=res.num[i]+'0';
            }
            return ans;
        }
        else if(size==b.size)
        {
            BigInt var1(size),var2(size);
            for(int i=size-1,j=0;i>=0;i--,j++)
            {
                var1.num[j]=num[i]-'0';
            }
            for(int i=b.size-1,j=0;i>=0;i--,j++)
            {
                var2.num[j]=b.num[i]-'0';
            }
            if(var1.num[0]>=var2.num[0])
            {
                BigInt res(var1);
                for(int i=0;i<var1.size;i++)
                {
                    if(int(var1.num[i]) >= int(var2.num[i]))
                    {
                        res.num[i]=var1.num[i] - var2.num[i];
                    }
                    else
                    {
                        res.num[i+1]=var1.num[i+1]-1;
                        res.num[i]=int(var1.num[i] + 10 - var2.num[i])%10;
                    }
                }
                for(int i=res.size-1;i>0;i--)
                {
                    if(res.num[i]!=0)
                    {
                        break;
                    }
                    res.size--;
                }
                BigInt ans(res.size);
                for(int i=res.size-1,j=0;i>=0;i--,j++)
                {
                    ans.num[j]=res.num[i]+'0';
                }
                return ans;
            }
            else
            {
                BigInt res(var2);
                for(int i=0;i<var2.size;i++)
                {
                    if(int(var2.num[i])>= int(var1.num[i]))
                    {
                        res.num[i]=var2.num[i] - var1.num[i];
                    }
                    else
                    {
                        res.num[i+1]=var2.num[i+1]-1;
                        res.num[i]=int(var2.num[i] + 10 - var1.num[i])%10;
                    }
                }
                for(int i=res.size-1;i>0;i--)
                {
                    if(res.num[i]!=0)
                    {
                        break;
                    }
                    res.size--;
                }
                BigInt ans(res.size);
                for(int i=res.size-1,j=0;i>=0;i--,j++)
                {
                    ans.num[j]=res.num[i]+'0';
                }
                return ans;
            }

        }
        else
        {
            BigInt var1(b.size),var2(b.size);
            for(int i=size-1,j=0;i>=0;i--,j++)
            {
                var1.num[j]=num[i]-'0';
            }
            for(int i=b.size-1,j=0;i>=0;i--,j++)
            {
                var2.num[j]=b.num[i]-'0';
            }
            BigInt res(var2);
            for(int i=0;i<var1.size;i++)
            {
                if(int(var2.num[i]) >= int(var1.num[i]))
                {
                    res.num[i]=var2.num[i] - var1.num[i];
                }
                else
                {
                    res.num[i+1]=var2.num[i+1]-1;
                    res.num[i]=int(var2.num[i] + 10 - var1.num[i])%10;
                }
            }
            for(int i=res.size-1;i>0;i--)
            {
                if(res.num[i]!=0)
                {
                    break;
                }
                res.size--;
            }
            BigInt ans(res.size);
            for(int i=res.size-1,j=0;i>=0;i--,j++)
            {
                ans.num[j]=res.num[i]+'0';
            }
            return ans;
        }
    }
////////////////////////////////////////////////////////////////////////////////
    BigInt operator-(unsigned long long int bint)
    {
        BigInt b(int(log10(bint))+1 , to_string(bint).c_str());
        BigInt res;
        res=*this-b;
        return res;
    }
///////////////////////////////////////////////////////////////
    BigInt operator*(BigInt b)
    {
        char carry=0;
        BigInt res(size+b.size-1),var1(size),var2(b.size);
        for(int i=var1.size-1,j=0;i>=0;i--,j++)
        {
            var1.num[j]=num[i]-'0';
        }
        for(int i=var2.size-1,j=0;i>=0;i--,j++)
        {
            var2.num[j]=b.num[i]-'0';
        }
        for(int i=0;i<var2.size;i++)
        {
            for(int j=0;j<var1.size;j++)
            {
                if(var1.num[j]*var2.num[i]<10)
                {
                    res.num[i+j]+=var1.num[j]*var2.num[i];
                }
                else
                {
                    res.num[i+j]+=int(var1.num[j]*var2.num[i])%10;
                    res.num[i+j+1]+=int(var1.num[j]*var2.num[i])/10;
                }
            }
        }
        for(int i = 0;i < res.size;i++)
        {
            carry = res.num[i]/10;
            res.num[i] = res.num[i]%10;
            res.num[i+1] = res.num[i+1] + carry;
        }
        for(int i=res.size-1;i>0;i--)
            {
                if(res.num[i]!=0)
                {
                    break;
                }
                res.size--;
            }
            BigInt ans(res.size);
            for(int i=res.size-1,j=0;i>=0;i--,j++)
            {
                ans.num[j]=res.num[i]+'0';
            }
            return ans;
    }
//////////////////////////////////////////////////////
    BigInt operator*(unsigned long long int bint)
    {
        if(bint==0)
        {
             BigInt res(1,"0");
            return res;
        }
        else
        {
            BigInt b(int(log10(bint))+1 , to_string(bint).c_str());
            BigInt res((*this)*b);
            return res;
        }


    }
/////////////////////////////////////////////////////
    void operator=(const BigInt b)
    {
        strcpy(num,b.num);
        size=b.size;
    }
///////////////////////////////////////////////////////////
        void operator=(unsigned long long int bint)
    {
        BigInt b(int(log10(bint))+1 , to_string(bint).c_str());
        strcpy(num,b.num);
        size=b.size;
    }
///////////////////////////////////////////////
    bool operator==(BigInt b)
    {
        bool flag=0;
        int check=0;
        if(size==b.size)
        {
            for(int i=0;i<size;i++)
            {
                if(this->num[i]-b.num[i]==0)
                {
                    check++;
                }
            }
            if(check==size)
            {
                flag=1;
            }
        }
        return flag;
    }
///////////////////////////////////////////////////////
    bool operator==(unsigned long long int bint)
    {
        BigInt b(int(log10(bint))+1 , to_string(bint).c_str());
        return *this==b;
    }
///////////////////////////////////////////////////////////////
    bool operator>=(BigInt b)
    {
        bool flag=0;
        int check=0;
        if(size>b.size)
        {
            flag=1;
        }
        if(size==b.size)
        {
            for(int i=0;i<size;i++)
            {
                if(this->num[i]-b.num[i]>=0)
                {
                    check++;
                }
            }
            if(check==size)
            {
                flag=1;
            }
        }
        return flag;
    }
/////////////////////////////////////////////////////////
    bool operator>=(unsigned long long int bint)
    {
        BigInt b(int(log10(bint))+1 , to_string(bint).c_str());
        return *this>=b;
    }
////////////////////////////////////////////////////////////
    void operator-=(BigInt b)
    {
        *this=*this-b;
    }
//////////////////////////////////////////////////////////////////
    void operator-=(unsigned long long int bint)
    {
        BigInt b(int(log10(bint))+1 , to_string(bint).c_str());
        *this-=b;
    }
//////////////////////////////////////////////////////////////////
    char operator[](int i)
    {
        return num[i-1];
    }
///////////////////////////////////////////////////////////////
// Note that conversion-type-id "int" is the implied return type.
// Returns by value so "const" is a better fit in this case.
    operator string () const
    {
        string str(num);
        return str;
    }
friend ostream &operator << (ostream &out, const BigInt &b)
{
    out<<"Size:"<<b.size<<endl<<"Number:"<<b.num<<endl;
    return out;
}
friend istream &operator >> (istream &in, BigInt &b)
{
    cout <<"Size:";
    in >> b.size;
    cout<<"Number:";
    string str;
    in>>str;
    strcpy(b.num,str.c_str());
    return in;
}
BigInt operator<<(int a)
{
    int b=pow(2,a);
    return *this*b;
}
BigInt &operator--()
{
    *this= (*this) - 1;
    return *this;
}
BigInt operator--(int i)
{
    BigInt temp=*this;
    *this=*this-1;
    return temp;
}



};





int main()
{
    char a[]="3" ,ch[]="10450";
    BigInt b(1,a),c(5,ch),nu1,nu2;
    c.get_data();
    b.get_data();
    (b-c).get_data();
    (b*0).get_data();
    c=b;
    b.get_data();
    cout<<string(c+b)<<endl;
    cout<<string(c+973)<<endl;
    (b+c).get_data();
    if(b==c)
    cout<<1<<endl;
    if(b==123)
    cout<<2<<endl;
    BigInt d=b*0;
    d.get_data();
    if(b>=1)
    cout<<3<<endl;
    cout<<string(b-1458)<<endl;
    b-=c;
    b.get_data();
    cout<<c[1]<<endl;
    cout<<string(c)<<endl;
    cin>>nu1>>nu2;
    cout<<nu1<<nu2;
    cout<<(c<<4);
    cout<<--c;
}