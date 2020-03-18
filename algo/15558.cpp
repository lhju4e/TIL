#include <stdio.h>
#include <queue>
using namespace std;
bool map[2][100001];
int check[2][100001];
int main()
{
    queue<pair<bool, int>> q; // 0이 1번맵 1이 2번맵
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%1d", &map[0][i]);
    for (int i = 1; i <= n; i++)
        scanf("%1d", &map[1][i]);

    q.push({false, 1}); // 맵, 위치
    int cnt = 0;
    while (!q.empty())
    {
        bool x = q.front().first;
        int y = q.front().second;
        q.pop();
        // printf("%d %d\n", x, y);
        if (y + 1 > n || y + k > n)
        {
            printf("1");
            return 0;
        }
        cnt = check[x][y] + 1;

        if (y - 1 > cnt && y - 1 >= 1 && map[x][y - 1])
        {
            q.push({x, y - 1});
            map[x][y - 1] = false;
            check[x][y - 1] = cnt;
        }
        if (y + 1 > cnt && y + 1 >= 1 && map[x][y + 1])
        {
            q.push({x, y + 1});
            map[x][y + 1] = false;
            check[x][y + 1] = cnt;
        }
        if (y + k >= cnt && y + k >= 1 && map[!x][y + k])
        {
            q.push({!x, y + k});
            map[!x][y + k] = false;
            check[!x][y + k] = cnt;
        }
    }
    printf("0");
    return 0;
}