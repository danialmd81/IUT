#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char* Delete(char* st, int size, int index) 
{
	for (int i = index; i < size; i++) 
    {
        st[i] = st[i + 1];
    }
    st[size - 1] = '\0';
    return st;
}
int IsOne(char* st1, char* st2, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        if (st1[i] != st2[i])
        {
            return 0;
        }
    }
    return 1;
}

void copy(char* st1, char* st2) 
{
    for (int i = 0; i < strlen(st2); i++) 
    {
        st1[i] = st2[i];
    }
    st1[strlen(st2)] = '\0';
}
int IsLike(char* st11, char* st22) 
{
    char st1[51];
    char st2[51];
    copy(st1, st11);
    copy(st2, st22);
    int size1 = strlen(st1);
    int size2 = strlen(st2);
    if (size1 == size2) 
    {
        int IsOkay = 1;
        for (int i = 0; i < size1; i++)
            if (tolower(st1[i]) != tolower(st2[i])) 
            {
                IsOkay = 0;
                break;
            }
        if (IsOkay)
        return 1;
        int ekh = 0;
        for (int i = 0; i < size1; i++) 
        {
            if (st1[i] != st2[i])
                ekh++;
            if (ekh >= 2) 
            {
                return 0;
            }
        }
        return 1;
    }
    else if (size1 - size2 == 1) 
    {
        for (int i = 0; i < size2; i++) 
        {
            if (st2[i] != st1[i]) 
            {
                if (IsOne(Delete(st1, size1, i), st2, size2)) 
                {
                    return 1;
                }
                else 
                {
                    return 0;
                }
                }
        }
        return 1;
    }
    else if (size2 - size1 == 1) 
    {
        for (int i = 0; i < size1; i++) 
        {
            if (st2[i] != st1[i]) 
            {
                if (IsOne(Delete(st2, size2, i), st1, size1)) 
                {
                    return 1;
                }
                else 
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    return 0;
}
int main(void) 
{
    int n, k;
    scanf("%d %d", &n, &k);
    char testcase[50][50];
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", testcase[i]);
    }
    char test[50][50];
    for (int i = 0; i < k; i++) 
    {
        scanf("%s", test[i]);
    }
    for (int i = 0; i < k; i++) 
    {
        int error = 0;
        for (int j = 0; j < n; j++) 
        {
            if (IsLike(testcase[j], test[i])) 
            {
                error++;
            }
        }
        printf("%d\n", error);
    }
}