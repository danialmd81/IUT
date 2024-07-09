#include <stdio.h>
#include <string.h>

int l1,l2,mulnum[200]={0},i,j,tmp;

void mul(int* num1,int* num2)
{
    for(i = 0;i < l2;i++)
    {
        for(j = 0;j < l1;j++)
        {
            mulnum[i+j] += num2[i]*num1[j];
        }
    }
    for(i = 0;i < l1+l2;i++)
    {
        tmp = mulnum[i]/10;
        mulnum[i] = mulnum[i]%10;
        mulnum[i+1] = mulnum[i+1] + tmp;
    }
}
int main()
{
    int num1[100],num2[100];
    char s1[101],s2[101];
    scanf(" %s",s1);
    scanf(" %s",s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    for(i = l1-1,j=0;i>=0;i--,j++)
    {
        num1[j] = s1[i]-'0';
    }
    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        num2[j] = s2[i]-'0';
    }
    mul(num1,num2);
    for(i=l1+l2-1;i >= 0;i--)
    {
        printf("%d",mulnum[i]);
    }
    return 0;
}