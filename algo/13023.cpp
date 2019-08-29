#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    vector <int> a[2000];
    int n, m;
    int tmp1, tmp2;
    bool result = false;
    int cnt = 0;

//인접리스트 생성
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &tmp1, &tmp2);
        a[tmp1].push_back(tmp2);
        a[tmp2].push_back(tmp1);
    }
    for(int i=0; i<n; i++)
    {
        
    }
}