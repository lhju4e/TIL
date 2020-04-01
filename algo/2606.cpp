#include <stdio.h>
#include <vector>
using namespace std;
int p[101];
void Union(int, int);
int find(int);
int main()
{
    int n, m;
    int a, b;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        p[i] = i;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        Union(a, b);
    }
    int ans=0;
    for(int i=2; i<=n; i++)
       if(find(i) == 1)
            ans++;
    printf("%d", ans);
    return 0;
}
void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x<y)
        p[y] = x; 
    else
        p[x] = y;
}

int find(int x)
{
    if(x == p[x])
        return x;
    else
    {
        int y = find(p[x]);
        p[x] = y;
        return y;
    }
}