#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void make(char* s)
{
    int n=strlen(s);
        for (int i = n; i < 2*n; i++) 
        {
            if (s[i - n] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        s[2 * n] = '\0';
}
int main()
{
    int L, R;
    scanf("%d %d", &L, &R);
    char* s=malloc(R*sizeof(char));
    s[0] = '1';
    s[1] = '\0';
    
    while (strlen(s)<R)
    make(s);
    int i=L-1;
    while(i<R)
    {
        printf("%c",s[i]);
        i++;
    }
}