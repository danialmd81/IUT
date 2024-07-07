#include<stdio.h>
long long int H (int n){
    if(n==0)
    return 5;
    if(n==1)
    return -3;
    if(n==2)
    return 1;
    return 3*H(n-1)-2*H(n-2)+H(n-3);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%lld",H(n));
}