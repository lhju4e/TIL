#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int gcd(int, int);
int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    printf("%d\n", gcd(a, b));
    printf("%d", (a*b)/gcd(a, b));
    return 0;
}

int gcd(int a, int b)
{
    int r;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;  
    }
    return a;
}