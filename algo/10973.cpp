#include <stdio.h>
#include <algorithm>
int main()
{
    int n;
    int a[10001] = {0};
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    if(std::prev_permutation(a, a+n) ==true)
       {
        for(int i=0; i<n; i++)
            printf("%d ", a[i]);
       }
    else
        printf("-1");
    return 0;
}