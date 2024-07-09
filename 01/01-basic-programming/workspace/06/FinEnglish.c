#include<stdio.h>
#include<math.h>
int halat=0;
void loop(int i)
{
    char harf[6];
    if(i<6)
    {
        scanf("%c",&harf[i]);
        if(harf[i]=='a'||harf[i]=='e'||harf[i]=='i'||harf[i]=='o'||harf[i]=='u')
        {
            halat++;
        }
        loop(i+1);
    }
    
}
int main()
{
    char harf[6];
    int a;
    loop(0);
    //printf("%d\n",halat);
    a=pow(2,halat);
    printf("%d",a);
}