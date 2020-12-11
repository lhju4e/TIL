#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int MAP[126][126];
int visit[126][126];
int INF = 1000000;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int n)
{
    memset(visit, INF, sizeof(visit));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visit[0][0] = MAP[0][0];

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx >= 0 && my >= 0 && my < n && mx < n)
            {
                if (visit[mx][my] > visit[x][y] + MAP[mx][my])
                {
                    visit[mx][my] = visit[x][y] + MAP[mx][my];
                    q.push(make_pair(mx, my));
                }
            }
        }
    }

    return visit[n-1][n-1];
}

int main()
{
    int n = 0;
    int cnt = 0;
    cin >> n;
    while (n != 0)
    {
        cnt++;
        memset(MAP, 0, sizeof(MAP));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> MAP[i][j];  

        cout << "Problem " << cnt << ": " << bfs(n) << endl;

        cin >> n;
    }
}