#include <stdio.h>

void ShowFibNth (long int n , long int n1){
    long int a ;
    if (n==1 && n1==1)
    {
        printf("%d", 1);
        return;
    }

    if (n==1)
    {
        printf("%d\n%d", 1, 1);
        return;
    }
    printf("%ld\n",n);
    a=n1-n;
    n1=n;
    n=a;
    ShowFibNth (n,n1);
}

int main (){
	long int a,b;
	scanf ("%ld\n%ld" , &a,&b);
	ShowFibNth (a,b);
	return 0;
}

