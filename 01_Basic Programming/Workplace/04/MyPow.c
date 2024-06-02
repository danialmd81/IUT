#include <stdio.h>

long double pow(long double base, unsigned exp);

int main()
{
    long double base, power;
    unsigned int exp;
    scanf("%Lf\n", &base);
    scanf("%u", &exp);
    power = pow(base, exp); 
    printf("%.3Lf",power);
    return 0;
}
long double pow(long double base, unsigned exp)
{
    if(exp == 0)
        return 1;
    else if(exp > 0)
        return base * pow(base, exp - 1);
}