#include <stdio.h>
using namespace std;
int p[1000001];
int find(int x);
void Union(int x, int y);
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        p[i] = i;
    int a, b, c;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a) // 같은 집합인지 확인
        {
            if(find(b) == find(c))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
            Union(b, c);
    }
    return 0;
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

void Union(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if(a!=b)
        p[b] = a;
}

