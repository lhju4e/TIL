#include <stdio.h>
int a[100001];
int ans = 0;
int n, s;
int main()
{
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int start_index = 0;
    int end_index = 0;
    int b = 0;
    int MIN = 100001;
    while (start_index <= end_index && end_index <= n)
    {
        printf("%d %d %d\n", start_index, end_index, b);
        if (b >= s)
        {
            ans = end_index - start_index;
            if (ans < MIN)
                MIN = ans;
            b -= a[start_index];
            start_index++;
        }
        else
        {
            b += a[end_index];
            end_index++;
        }
    }

    if (MIN == 100001)
        printf("0");
    else
        printf("%d", MIN);
    return 0;
}
