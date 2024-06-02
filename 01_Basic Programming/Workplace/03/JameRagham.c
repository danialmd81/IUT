#include <stdio.h>

int main(){
    long long int n, sum, a, b;
    scanf("%lld", &n);
    while(n>=10){
        a=n%10;
        b=n/10;
        sum=a+b;
        n=sum;
    }
    printf("%lld", n);

    return 0;
}