#include<stdio.h>

int main()
{
    char message[1000]={}, ch,a,b;
    int i, key=0;
    scanf("%c\n%c\n%s",&a,&b,&message);
    key= a-b;
    for(i = 0; message[i] != '\0'; ++i)
    {
        if(key>0)
        {
        message[i]=((message[i]+key)-97)%26+97;
        }
        else
        {
            if(message[i]+key<97)
            message[i]=message[i]+key+26;
            else
            message[i]=message[i]+key;
        }
    }
    
    printf("%s", message);
    return 0;
}