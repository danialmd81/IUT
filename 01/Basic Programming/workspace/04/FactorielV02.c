#include <stdio.h>
long fact (int x){
	if (x==1)
		return 1;
	return x * fact (x-1);
}
int main (){
	int x;
	scanf("%d",&x);
	printf("%d",fact(x));
	return 0;
}
