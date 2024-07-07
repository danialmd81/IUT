// Basic Euclidean Algorithm
#include <iostream>

using namespace std;

unsigned int gcd(unsigned int a, unsigned int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()

{
    cout << gcd(15, 10);
}