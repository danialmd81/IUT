#include<iostream>
#include<string>

using namespace std;

int  khafan(int a, int b)
{
    return a+b;
}

bool  khafan(bool a, bool b)
{
    return a&&b;
}

float  khafan(float a, float b)
{
    return a&&b;
}

string khafan(string a, string b)
{
    a.append(b);
    return a;
}

int *khafan(int *a,int *b,int sizea,int sizeb)
{
    int* out=new int [sizea+sizeb];

    for(int i=0;i<sizea;i++)
    {
        out[i]=a[i];
    }

    for(int i=sizea,j=0;i<sizeb+sizea;i++,j++)
    {
        out[i]=b[j];
    }
    return out;
}

float *khafan(float *a,float *b,int sizea,int sizeb)
{
    float* out=new float [sizea+sizeb];
    for(int i=0;i<sizea;i++)
    {
        out[i]=a[i];
    }
    for(int i=sizea,j=0;i<sizeb+sizea;i++,j++)
    {
        out[i]=b[j];
    }
    return out;
}

string khafan(int *a, float *b,int sa,int sb)
{
    return string("Different Types");
}

string khafan(float *a, int *b,int sa,int sb)
{
    return string("Different Types");
}

int main()
{
    cout<<khafan(10,20)<<endl;
    cout<<khafan(true,false)<<endl;
    cout<<khafan(string("ali"),string("mamad"))<<endl;
    int a[]={1,2,3,4},b[]={5,6,7,8,9};
    int na=sizeof(a)/sizeof(a[0]),nb=sizeof(b)/sizeof(b[0]);
    for(int i=0;i<na+nb;i++)
    cout<<khafan(a,b,na,nb)[i]<<endl;
    float a1[]={1.1,1.2,1.3},b1[]={2.1,2.2,2.3,2.4};
    int na1=sizeof(a1)/sizeof(a1[0]),nb1=sizeof(b1)/sizeof(b1[0]);
    for(int i=0;i<na1+nb1;i++)
    cout<<khafan(a1,b1,na1,nb1)[i]<<endl;
    cout<<khafan(a,b1,na1,nb1)<<endl;
    cout<<khafan(a1,b,na1,nb1)<<endl;

}