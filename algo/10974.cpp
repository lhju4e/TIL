#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int a[8] = {0};
    for(int i=0; i<n; i++)
        a[i] = i+1;
    do{
        for(int i=0; i<n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }while(next_permutation(a, a+n));
}