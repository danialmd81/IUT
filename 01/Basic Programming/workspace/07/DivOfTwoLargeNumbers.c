#include<stdio.h>
#include<string.h>
int l1,l2,divnum[150],i,j;
void div(int* num1,int* num2)
{
    
}
int main()
{
    int num1[55],num2[55];
    char s1[55],s2[55];
    gets(s1);
    l1=strlen(s1);
    gets(s2);
    l2=strlen(s1);
    for(i = l1-1,j=0;i>=0;i--,j++)
    {
        num1[j] = s1[i]-'0';
    }
    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        num2[j] = s2[i]-'0';
    }
    div(num1,num2);
    for(i=l1+l2-1;i >= 0;i--)
    {
        printf("%d",divnum[i]);
    }
    return 0;
}