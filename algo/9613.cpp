#include <stdio.h>
int gcd(int, int);
int main()
{
    int t, n, tmp;
    long long sum=0;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d", &n);
        int *a = new int[n];
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                sum += gcd(a[i], a[j]);
        printf("%lld\n", sum);
        sum = 0;
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