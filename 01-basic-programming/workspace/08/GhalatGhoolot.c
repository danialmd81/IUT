#include <stdio.h>
#include<string.h>

int main() 
{
    char s[100000] = { 0 };
    gets(s);
    int n = strlen(s);
    int k = 0;
    char s1[100000] = { 0 };
    for (int i = n, j = 0; i >= 0; i--) 
    {
        if (s[i] == '=') 
        k--;
        else 
        {
            if ( k > 0) 
            {
                s1[j] = s[i]; 
                j++;
            }
            else 
            k++;
        }
    }
    n = strlen(s1);
    int j = 0;
    for (int i = n; i > 0; i--) 
    {
        s[j] = s1[i-1]; 
        j++;
    }
    s[j] = '\0';
    puts(s);
}