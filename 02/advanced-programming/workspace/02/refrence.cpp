#include <iostream>

using namespace std;

void update(int &a,int &b)
{
    int temp;
    temp=(a)+(b);
    b=b>a?b-a:a-b;
    a=temp;

}



int main()
{
    int a,b;

    cin>>a>>b;
    update(a,b);
    cout<<a<<endl<<b;
    return 0;
}