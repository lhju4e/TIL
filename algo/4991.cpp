#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
char map[21][21];
int dist[12][12];
int w, h;
int bfs(int, int, int, int);
int main()
{
    while (1)
    {
        pair<int, int> start;
        int MIN = 4000;
        vector<pair<int, int>> v; // 더러운 칸 좌표 저장.
        vector<int> order;        // 순열만들기위함.
        int dirty = 0;
        memset(dist, 0, sizeof(dist));
        memset(map, 0, sizeof(map));
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        for (int i = 0; i < h; i++)
        {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < w; j++)
            {
                map[i][j] = tmp.at(j);
                if (map[i][j] == 'o')
                    start = make_pair(i, j);
                else if (map[i][j] == '*')
                {
                    v.push_back(make_pair(i, j));
                    dirty++;
                    order.push_back(dirty);
                }
            }
        }
        if (dirty == 0)
        {
            cout << "0" << endl;
            continue;
        }

        for (int i = 0; i < dirty; i++)
            for (int j = 0; j < dirty; j++)
            {
                if (i == j)
                    continue;
                if(!dist[i+1][j+1])
                dist[i + 1][j + 1] = bfs(v[i].first, v[i].second, v[j].first, v[j].second);
            }
        for (int i = 0; i < dirty; i++)
            dist[0][i + 1] = bfs(start.first, start.second, v[i].first, v[i].second);
        do
        {
            int a = dist[0][order[0]];
            if (a == 0)
                continue;
            for (int i = 0; i < order.size() - 1; i++)
            {
                int b = dist[order[i]][order[i + 1]];
                a += b;
                if (b == 0)
                    continue;
            }
            if (MIN > a)
                MIN = a;
        } while (next_permutation(order.begin(), order.end()));

        if (MIN == 4000 || MIN == 0)
            cout << "-1" << endl;
        else
            cout << MIN << endl;
    }
    return 0;
}

int bfs(int x, int y, int a, int b)
{
    // cout << "a " << a << " b " << b << endl;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int check[21][21];
    memset(check, 0, sizeof(check));
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int mx = x + dx[i];
            int my = y + dy[i];

            if (mx >= 0 && my >= 0 && mx < h && my < w && !check[mx][my] && map[mx][my] != 'x')
            {
                check[mx][my] = check[x][y] + 1;
                if (mx == a && my == b)
                    return check[a][b];
                else
                    q.push(make_pair(mx, my));
            }
        }
    }
    return 0;
}
