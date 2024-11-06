#include<stdio.h>
int main()
{
    char  ascii;
    int len ,num=0;
    for (len=0;ascii!='\n';len++)
    {
        scanf("%c",&ascii);
        num = num * 10 + (ascii - '0');
        if (num >= 32) 
        {
			char ch = (char)num;
			printf("%c",ch);
			num = 0;
		}     
    }
}
