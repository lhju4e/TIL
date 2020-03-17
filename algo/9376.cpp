#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
char cm[101][101];
int h, w;
int target;
int bfs(int, int);
int bfs2(int, int, int [101][101]);
int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        target = 0;
        int ans = 100000;
        queue<pair<int, int>> q;
        memset(cm, 0, sizeof(cm));
        cin >> h >> w;
        cout << "h w : " << h << " " << w << endl;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                cin >> cm[i][j];
                if (i == 0 || i == h - 1 || j == 0 || j == w - 1) // 출입구 찾기
                    if (cm[i][j] == '#' || cm[i][j] == '.')
                        q.push(make_pair(i, j));
            }
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int a = bfs(x, y);
            cout << "ans :" << a << endl;
            if (a < ans)
                ans = a;
        }
        cout << ans << endl;
        cout << "======================================="<<endl;
    }
    return 0;
}

int bfs(int x, int y) // *이 아닌 곳만 돌아다니기.
{
    cout << "bfs " <<x << " " << y<< endl;
    int ans = 0;
    vector<pair<int, int>> v;
    queue<pair<int, int>> q;
    bool check[101][101]; // 간곳 다시 안가게 체크
    int back[101][101];   //
    memset(check, 0, sizeof(check));
    memset(back, 0, sizeof(back));
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    q.push(make_pair(x, y));
    // v.push_back(make_pair(x, y));

    check[x][y] = true;
    if (cm[x][y] == '#')
        back[x][y] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // int x = v.back().first;
        // int y = v.back().second;
        // v.pop_back();

        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >=0 && b >=0 && a < h && b < w && cm[a][b] != '*' && !check[a][b])
            {
                q.push(make_pair(a, b));
                // v.push_back(make_pair(a, b));

                check[a][b] = true;
                if (cm[a][b] == '#' && (back[a][b] == 0))
                {
                    back[a][b] = back[x][y] + 1;
                }
                else
                {
                    back[a][b] = back[x][y];
                }
                if (cm[a][b] == '$')
                {
                                        for(int n=0; n<5; n++)
                        {for(int m=0; m<9; m++)
                        cout << back[n][m] << " ";
                        cout << endl;
                        }
                        cout << "================"<<endl;
                    ans = bfs2(a, b, back);
                    for(int n=0; n<5; n++)
                        {for(int m=0; m<9; m++)
                        cout << back[n][m] << " ";
                        cout << endl;
                        }
                    cout << back[a][b] << endl;
                    return ans+back[a][b];
                }
            }
        }
    }
}

int bfs2(int x, int y, int back[101][101])
{
    queue<pair<int, int>> q;
    bool check[101][101]; // 간곳 다시 안가게 체크
    memset(check, 0, sizeof(check));
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int ans = 0;
    q.push(make_pair(x, y));
    check[x][y] = true;
    // v.push_back(make_pair(x, y));
   while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // int x = v.back().first;
        // int y = v.back().second;
        // v.pop_back();

        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >=0 && b >=0 && a < h && b < w && cm[a][b] != '*' && !check[a][b])
            {
                q.push(make_pair(a, b));
                // v.push_back(make_pair(a, b));

                check[a][b] = true;

                if (cm[a][b] == '$')
                {
                    if(!back[a][b] || back[a][b] > back[x][y])
                        {back[a][b] = back[x][y];     
                        ans = back[a][b];}   
                }
                else if (cm[a][b] == '#' && (back[a][b] == 0))
                {
                    back[a][b] = back[x][y] + 1;
                }
                else
                {
                    back[a][b] = back[x][y];
                }
            }
        }
    }
    cout << "bfs2 " << ans << endl;
    return ans;
}