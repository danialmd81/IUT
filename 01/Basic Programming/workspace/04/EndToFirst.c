 #include<stdio.h>

int sort (int n)
{

    scanf("%d", &n);

    if(n==0)
    {
        return 0;
    }
    
    sort(n);
    printf("%d -->",n);
    
    return 0;
}
int main()
{

    sort(10);

}
