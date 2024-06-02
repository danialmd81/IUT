#include <stdio.h>
#include <math.h>

int main(){
    long long int a, b, c, d, e, f, n;
    scanf("%lld%lld%lld", &a, &b, &c);
    e=0;
for(n=0; a!=0; n++){
    d=(a%10)*round(pow(b,n));
    a=a-(a%10); a=(a/10);
    e=(e+d);
}
    a=e; d=0; e=0; n=0;
for(n=0; a!=0; n++){
    d=(a%c)*round(pow(10,n));
    a=a-(a%c); a=(a/c);
    e=(e+d);
}
    a=e; f=0; d=0; n=0;
for(n=0; a!=0; n++){
    d=(a%10);
    a=a-(a%10); a=(a/10);
    f=(f*10); f=(f+d);
}
if(f==e)
    puts("YES");
else
    puts("NO");

return 0;
}