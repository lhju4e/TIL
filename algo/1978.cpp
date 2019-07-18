#include <stdio.h>
bool prime(int);
int main()
{
    int n, count=0;
    bool tmp = false;
    scanf("%d", &n);
    int *a = new int[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        if(prime(a[i]) == true)
        {
            printf("true : %d", a[i]);
            count++;
        }
    }
    printf("%d", count);

    return 0;
}

bool prime(int a)
{
    if(a<2) // 1은 소수가 아님
        return false;
    for(int i=2; i*i<=a; i++)
    {
        if(a%i ==0)
            return false;
    }
    return true;
}