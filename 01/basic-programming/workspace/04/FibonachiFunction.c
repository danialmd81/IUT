#include <stdio.h>
long fibo (int n){
	return n==1||n==2?1:fibo (n-1)+fibo(n-2);
}
int main (){
	int a;
	scanf ("%d" , &a);
	printf ("%ld",fibo (a));
	return 0;
}

