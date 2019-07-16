#include <stdio.h>
int gcd(int, int);
int main()
{
    int t, a, b;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);

        printf("%d\n", (a*b)/gcd(a, b));
    }
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