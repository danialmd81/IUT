#include <stdio.h>
#include <math.h>
#include <string.h>
int def;
char* MUL(char* num1, int num2, char* MUL, int l) 
{
    int temp = 0;
    for (int i = l - 1; i >= 0; i--) 
    {
        temp += (num1[i] * num2);
        if (temp > 9) 
        {
            MUL[i] = temp % 10; temp /= 10;
        }
        else 
        { 
            MUL[i] = temp; temp = 0; 
        }
    }
    return MUL;
}
char* convertInt(char* number) 
{
    for (int i = 0; number[i] != '\0'; i++) 
    {
        number[i] -= 48;
    }
    return number;
}
char* next(char* arr, int l, int step) 
{
    for (int i = l - 1; i - step > -1; i--) 
    {
        arr[i] = arr[i - step]; arr[i - step] = 0;
    }
    return arr;
}
int compare(char* first_num, char* num2, int l) 
{
    for (int i = 0; i < l; i++) 
    {
        if (first_num[i] > num2[i])
        return 1;
        else if (first_num[i] < num2[i])
        return 0;
    }
    return 2;
}
char* SUB(char* first_num, char* num2, char* sub, int l) 
{
    int temp = 0;
    for (int i = l - 1; i >= 0; i--) 
    {
        temp += *(first_num + i) - *(num2 + i);
        if (temp < 0) 
        {
            *(sub + i) = 10 + temp; temp = -1;
        }
        else 
        { 
            *(sub + i) = temp;
            temp = 0; 
        }
    }
    return sub;
}
char* copy(char* first, char* second, int l) 
{
    for (int i = 0; i < l - 1; i++) 
    {
        second[i] = first[i];
    }
    return second;
}
char* DIV(char* first_num, char* num2, char* div, int l) 
{
    char temp_second_num[300] = { 0 }; 
    copy(num2, temp_second_num, l);
    for (int i = 0; i < l - 1; i++) 
    {
        int temp1 = 0;
        char guess[300] = { 0 };
        for (int j = 0; j < 10; j++) 
        {
            MUL(num2, j, guess, l);
            if ((compare(first_num, guess, l))) 
            {
                temp1 = j; 
            }
        }       
        div[i] = temp1; 
        MUL(num2, temp1, guess, l);
        SUB(first_num, guess, first_num, l);
        next(num2, l, 1);
    }
    return div;
}

int main() 
{
    char num1[300] = { 0 }, div[300] = { 0 }, num2[300] = { 0 }; 
    int l1 = 0, l2 = 0;
    int compare_check=0;
    gets(num1);
    gets(num2);
    l1 = strlen(num1)+1; 
    l2 = strlen(num2)+1;
    def = l1 - l2;
    compare_check=compare(num1,num2,300) ;
    convertInt(num1); 
    convertInt(num2);
    if(num2[0]==0&&num1[0]==0)
    {
        printf("NaN");
        return 0;
    }
    if(num2[0]==0)
    {
        printf("Can't divide by zero");
        return 0;
    }
    if(num1[0]==0)
    {
        printf("0");
        return 0;
    }
    next(num1,300, 1); 
    next(num2, 300, 1);
    DIV(num1, num2, div, 300);
    if(def<0||(compare_check==0&&def==0))
    {
       printf("0");
    }
    for(int i=299;div[i]==0&&i>=((def)+1);i--)
    {
        div[i]=-1;
    }

    if(compare_check)
    {
        int i=0;
        for(;i<def+1;i++)
        {
            printf("%d",div[i]);
        }
        if(div[i]>-1)
        {
        printf(".");
        for(;div[i]>-1;i++)
        {
            printf("%d",div[i]);
        }
        }

    }
    else 
    {
        int i=1;
        for(;i<def+1;i++)
        {
            printf("%d",div[i]);
        }
        if(div[i]>-1)
        {
            printf(".");
            for(;div[i]>-1;i++)
            {
                printf("%d",div[i]);
            }
        }
    }
}