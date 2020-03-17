#include <iostream>
#include <string>
#include <queue>
using namespace std;
char MAP[101][101];
// bool check[101][101];
int cnt[101][101];
int main()
{
    bool endcheck = false;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int ans = 0;
    int w, h;
    queue<pair<pair<int, int>, pair<int, int>>> q; // 방향 삳태와 좌표
    pair<int, int> end;
    string tmp;
    cin >> w >> h;
    for(int i=0; i<h; i++)
    for(int j=0; j<w; j++)
        cnt[i][j] = 1000000;
    for (int i = 0; i < h; i++)
    {
        cin >> tmp;
        for (int j = 0; j < w; j++)
        {
            MAP[i][j] = tmp.at(j);
            if (MAP[i][j] == 'C')
            {
                if (endcheck)
                    end = make_pair(i, j);
                else
                {
                    for (int k = 0; k < 4; k++)
                        q.push(make_pair(make_pair(k, 0), make_pair(i, j)));
                    cnt[i][j] = 0;
                    endcheck = true;
                    // check[i][j] = true;
                }
            }
        }
    }

    
    while (!q.empty())
    {
        int status = q.front().first.first;
        int count = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx >= 0 && my >= 0 && mx < h && my < w && MAP[mx][my] != '*')
            {
                int next = count;
                if (status != i)
                    next += 1;
                if (cnt[mx][my] >= next) // 이미 온 적이 있는데 이전값이 더 작으면
                {
                    cnt[mx][my] = next;
                    q.push(make_pair(make_pair(i, next), make_pair(mx, my)));
                }
            }
        }
    }
    // for(int i=0; i<h; i++)
    // {
    //     for(int j=0; j<w; j++)
    //         cout << cnt[i][j];
    //     cout << endl;
    // }

    cout << cnt[end.first][end.second] << endl;
    return 0;
}