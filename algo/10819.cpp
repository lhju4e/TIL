#include <stdio.h>
#include <algorithm>
#include <math.h>
int main()
{
    int n;
    int max=0, sum=0;
    scanf("%d", &n);
    int a[8] = {0};
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    std::sort(a, a+n);
    do{
        for(int i=0; i<n-1; i++)
            sum += abs(a[i] - a[i+1]);
        if(max < sum)
            max = sum;
        sum = 0;
    }while(std::next_permutation(a, a+n));
    printf("%d", max);
    return 0;
}