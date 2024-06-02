#include<stdio.h>
int main()
{
    int n,i;
    char x1,x2,y;
    scanf("%d %c\n",&n,&y);
    for(i=0;i<n;i++)
    {
        scanf("%c %c\n",&x1,&x2);
        if (y==x1){
            y=x2;
        }
        else if (y==x2){
            y=x1;
        }
    }
    printf("%c",y);
    return 0;
    










}
