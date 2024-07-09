#include <stdio.h>


void update(int *a,int *b)
{
    int temp;
    temp=(*a)+(*b);
    *b=*b>*a?*b-*a:*a-*b;
    *a=temp;

}

int main()
{
    int a,b;
    scanf("%d %d", &a ,&b);
    update(&a,&b);
    printf("%d\n%d",a,b);
    return 0;
}