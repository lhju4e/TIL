#include <stdio.h>
#include <algorithm>
int main()
{
    int a[9];
    int sum = 0;
    for(int i=0; i<9; i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    std::sort(a, a+9);
    for(int i=0; i<9; i++)
        for(int j=i+1; j<9; j++)
        {
            if(sum - a[i] - a[j] == 100)
            {
               for(int k=0; k<9; k++)
                {
                    if(k == i || k==j)
                        continue;
                   printf("%d\n", a[k]);
                }
                return 0;
            }
        }
    return 0;
}