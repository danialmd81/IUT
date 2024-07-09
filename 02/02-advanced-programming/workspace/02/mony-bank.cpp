#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int all_money=0,all_ok_wit_money=0,out_money=0,temp=0,flag=1;
class mony
{
    public:
    string operation;
    int money;
    string time;
    bool result;
    mony()
    {

        cin>>operation;
        cin>>money;
        cin>>time;
        if(operation=="WIT")
        {
            string s;
            cin>>s;
            if(s=="FAIL")
            {
                result=false;
            }
            if(s=="OK")
            {
                result=true;
            }
        }
    }
    void mony_out()
    {
        cout<<operation<<" ";
        cout<<money<<" ";
        cout<<time<<" ";
        if(operation=="WIT")
        cout<<result<<" ";
    }
};

bool time_compare(mony t1,mony t2)
{
    return (t1.time<t2.time);
}



int main()
{
    int n;
    cin>>n;
    vector<mony> m(n);
    for(int i=0;i<n;i++)
    {
        m.at(i);
    }
    sort(m.begin(),m.end(),time_compare);
    for(int i=0;i<n;i++)
    {
        if(m.at(i).operation=="DEP")
        {
            all_money=all_money+m.at(i).money;
        }
        if(m.at(i).operation=="WIT")
        {
            if(m.at(i).result)
            {
                all_ok_wit_money=all_ok_wit_money+m.at(i).money;
            }
            if(!m.at(i).result&&all_money>=m.at(i).money)
            flag=0;
        }
        temp=all_money-all_ok_wit_money;
        if(temp<0)
        {
            out_money=out_money-temp;
            all_money=0;
            all_ok_wit_money=0;
        }
    }
    if(flag)
        cout<<out_money;
    else
    {
        cout<<"DOROGHE";
    }

}