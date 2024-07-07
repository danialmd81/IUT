#include<iostream>

using namespace std;

int main()
{
    string s,word;
    cin>>s;
    int i=0,j=0;
    while(i<s.length())
    {
        if('a'<=s[i] && s[i]<='z')
        {
            word.insert(j,1,s[i]);
            j++;
        }
        else if(s[i]=='R' && j<word.length())
        {
            j++;
        }
        else if(s[i]=='L' && j>0)
        {
            j--;
        }
        i++;
    }
    cout<<word;
    return 0;
}
