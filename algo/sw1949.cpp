#include <iostream>
using namespace std;
int n;
int map[8][8];
int k, score;
bool check[8][8];

int dfs(int, int, bool, int);
int main()
{
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        score = 0;
        int tmp = 0;
        int ans = 0;
        int m = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                check[i][j] = false;
                cin >> map[i][j];
                if (map[i][j] > m)
                    m = map[i][j];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == m)
                {
                    tmp = dfs(i, j, true, 0);
                    // cout << "tmp " << tmp << endl;
                    if (ans < tmp)
                        ans = tmp;
                }
            }
        cout << "#" << t << " " << ans + 1 << endl;
    }
    return 0;
}

int dfs(int x, int y, bool cut, int len)
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    // cout << "x " << x << " y " << y << " cut " << cut << " leng " << len << endl;
    check[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int mx = dx[i] + x;
        int my = dy[i] + y;
        if (!check[mx][my] && mx >= 0 && mx < n && my >= 0 && my < n)
        {
            if (map[mx][my] < map[x][y])
            {
                int result = dfs(mx, my, cut, len + 1);
                if (score < result)
                    score = result;
            }
            else
            {
                if (cut && map[mx][my] - map[x][y] < k)
                {
                    int tmp = map[mx][my];
                    map[mx][my] = map[x][y] - 1;
                    int result = dfs(mx, my, false, len + 1);
                    if (score < result)
                        score = result;
                    map[mx][my] = tmp;
                }
            }
        }
    }
    check[x][y] = false;
    if(score > len)
        return score;
    else
        return len;
}