#include <stdio.h>
const int MAX = 1000000;
int f_prime(int n);
int func(int, int);
int prime[MAX];
bool check[MAX] = {true};
int main()
{
    int pn = 0, a = 0, b = 0;
    pn = f_prime(MAX);
    int n;
    while(1){
        scanf("%d", &n);
        if(n == 0)
            return 0; 
        if(func(pn, n) == -1)
            printf("Goldbach's conjecture is wrong.\n");   
    }
}
int f_prime(int n)
{
    int pn = 0;
    for(int i=2; i<=n; i++)
    {
        if(check[i] == false) // 지워지지 않은 경우 - 소수인 경우
            {
                prime[pn++] = i;
                for(int j=2*i; j<=n; j+=i)
                    check[j] = true;
            }
    }
    return pn;
}
int func(int pn, int n)
{
    int a, b;
     for(int i=0; i<pn; i++)
        {
            a = prime[i];
            b = n - a;
            if(check[b] == false)
            {
                printf("%d = %d + %d\n", n, a, b);
                return 0;
            }              
        }
    return -1;
}