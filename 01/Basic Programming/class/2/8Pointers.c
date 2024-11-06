#include<stdio.h>
#include<time.h>
#include <stdlib.h>
char *arr_maker(void)
{
    char* arr=malloc(2*sizeof(char));
    for(int i=0;i<2;i++)
    arr[i]=(char)(97+(rand()%25));
    return arr;
}

void arr_printer(char** arr)
{

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%c",(char)(*arr[i]+j));
        }
        printf(" ");
    }
}

void main_arr_maker(void)
{
    char* arrm[5];

    for(int i=0;i<5;i++)
    {
        arrm[i]=arr_maker();
    }
    arr_printer(arrm);
}

int main()
{    
    srand(time(NULL));
    main_arr_maker();
}

    