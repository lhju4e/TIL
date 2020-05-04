#include <iostream>
#include <queue>
using namespace std;
int MAP[8][8];
int COPY[8][8];
int N, M;
int MAX = 0;
void wall(int, int, int); // 벽 세우는 함수
int test();               // 벽이 세워진 뒤 바이러스를 퍼뜨리고 안전영역 체크
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }
    wall(0, 0, 0);
    cout << MAX;
    return 0;
}

void wall(int x, int y, int fin)
{
    if (fin == 3)
    {
        int result = test();
        //         for(int i=0; i<N; i++)
        // {
        //     for(int j=0; j<M; j++)
        //     {
        //         cout << MAP[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "result " << result << endl;
        if (MAX < result)
        {
            MAX = result;
        }
        return;
    }
    int j = y;
    for (int i = x; i < N; i++)
    {
        for (; j < M; j++)
        {
            if (MAP[i][j] == 0)
            {
                MAP[i][j] = 1;
                wall(i, j, fin + 1);
                MAP[i][j] = 0;
            }
        }
        j = 0;
    }
    return;
}

int test()
{
    int cnt = 0;
    queue<pair<int, int>> q;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            COPY[i][j] = MAP[i][j];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (COPY[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
        }
    }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int sx = x + dx[i];
            int sy = y + dy[i];
            if (sx >= 0 && sy >= 0 && sx < N && sy < M)
            {
                if (COPY[sx][sy] == 0)
                {
                    COPY[sx][sy] = 2;
                    q.push(make_pair(sx, sy));
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (COPY[i][j] == 0)
                cnt++;
    return cnt;
}