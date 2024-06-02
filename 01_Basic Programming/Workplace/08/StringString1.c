#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int conditon1(char testcase[],char test[])
{
    int x = strlen(testcase); int y = strlen(test);
    if (abs(x - y) != 1)
    return 0;
    if (x > y) 
    {
        for (int i = 0; i < y; i++) 
        {
            if (test[i] != testcase[i])
            {
                for (; i < y; i++) 
                {
                    if (test[i] != testcase[i + 1])
                    return 0;
                }
                return 1;
            }
        }
    }
    else {
        for (int i = 0; i < x; i++) 
        {
            if (test[i] != testcase[i]) 
            {
                for (; i < x; i++) 
                {
                    if (test[i + 1] != testcase[i])
                    return 0;
                }
                return 1;
            }
        }
    }

}
int conditon2(char testcase[],char test[])
{
    int counter = 0;
    int x = strlen(testcase); 
    int y = strlen(test);
    if (x != y)
    return 0;
    for (int i = 0; i < x; i++) 
    {
        if (test[i] != testcase[i]) 
        {
            counter++;
            if (counter > 1)
            return 0;
        }

    }
    return 1;
}
int conditon3(char testcase[],char test[])
{
    int counter = 0; char sw[51] = { 0 }, tw[51] = { 0 };
    int x = strlen(testcase); int y = strlen(test);
    if (x != y)
    return 0;
    for (int i = 0; i < x; i++) 
    {
        sw[i] = tolower(test[i]);
        tw[i] = tolower(testcase[i]);
        if (sw[i] != tw[i])
        counter++;
        if (counter > 0)
        return 0;
    }
    return 1;
}
int main()
{
    int n,k;
    char testcase[60][60], test[60][60];
    int ncon [60]={0};
    scanf("%d %d", &n , &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",&test[i]);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%s",&testcase[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int x=0;
             x=conditon1(testcase[j],test[i])+conditon2(testcase[j],test[i])+conditon3(testcase[j],test[i]);
        if (x > 0)
        ncon[j]++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d\n",ncon[i]);
    }
}