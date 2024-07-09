#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iterator>


using namespace std;

void help()
{
    cout<<"-h, --help        prints all commands in terminal."<<endl
    <<"-p, --palindrome    checks if input string is palindrome."<<endl
    <<"-c, --concatenate    concatenates all the input strings."<<endl
    <<"-s, --sort        sorts all of the input strings in alphabetic order."<<endl
    <<"-f, --find        find a substring in a string."<<endl
    <<"-r, --reverse        reverse all the input strings.;"<<endl;
}

bool palindrome(string arg)
{
    string P = arg;
    reverse(P.begin(), P.end());
    if (arg == P)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }
    return false;
}


int main(int argc , char *argv[])
{
    if(strcmp(argv[1],"-h")==0 ||strcmp(argv[1],"--help")==0)
    {
        help();
    }

    if(strcmp(argv[1],"-p")==0 ||strcmp(argv[1],"--palindrome")==0)
    {
        for (int i=2;i<argc;i++)
        {
            cout<<argv[i];
            palindrome(argv[i])?cout<<" is palindrome.":cout<<" is not palindrome.";cout<<endl;
        }
    }
    if(strcmp(argv[1],"-s")==0 ||strcmp(argv[1],"--sort")==0)
    {
        vector<string> v(argv + 2, argv + argc);
        sort(v.begin(), v.end());
        for (int i=0;i<argc-2;i++)
        {
            {
                cout<<v.at(i)<<endl;
            }
        }
    }
    if(strcmp(argv[1],"-r")==0 || strcmp(argv[1],"--reverse")==0)
    {
        vector<string> v(argv + 2, argv + argc);
        for (int i=0;i<argc-2;i++)
        {
            {
                reverse(v.at(i).begin(), v.at(i).end());
                cout<<v.at(i)<<endl;
            }
        }
    }
        if(strcmp(argv[1],"-f")==0 || strcmp(argv[1],"--find")==0)
    {
        isSubstring(argv[2],argv[3])?cout<<argv[2]<<" was found in "<<argv[3]:cout<<argv[2]<<" was not found in "<<argv[3];
    }
        if(strcmp(argv[1],"-c")==0 || strcmp(argv[1],"--concatenate")==0)
    {
        for (int i=argc-1;i>1;i--)
        {
            {
                strcat(argv[i-1],argv[i]);
            }
        }
        cout<<argv[2]<<endl;
    }
    return 0;
}