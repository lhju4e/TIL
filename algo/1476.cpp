#include <stdio.h>
int main()
{
    int a=0, b=0, c=0, e, s, m;
    int year = 0;
    scanf("%d %d %d", &e, &s, &m);
    while(1)
    {
        year++;
        a = year%15;
        b = year%28;
        c = year%19;
        if(a == 0) a = 15;
        if(b == 0) b = 28;
        if(c == 0) c = 19;
        if(a == e && b == s && c == m)
            {
                printf("%d", year);
                return 0;
            }
    }
}