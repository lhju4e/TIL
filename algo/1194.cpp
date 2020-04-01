#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
char MAP[51][51];
bool KEY[7];
bool use_key[7];
bool check[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
    int n, m;

int bfs(int, int, int, int);
queue<pair<pair<int, int>, char>> track; // 좌표, key : 가야하는 길

int main()
{
    int answer = -1;
    queue<pair<int, int>> q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            MAP[i][j + 1] = tmp.at(j);
            if (MAP[i][j + 1] == '0')
            {
                q.push(make_pair(i, j + 1));
                track.push(make_pair(make_pair(i, j + 1), '0'));
                check[i][j + 1] = true;
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // cout << "x " << x << " y " << y << endl;
        for (int i = 0; i < 4; i++)
        {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx >= 1 && mx <= n && my >= 1 && my <= m && !check[mx][my] && MAP[mx][my]!='#')
            {
                if (MAP[mx][my] >= 'a' && MAP[mx][my] <= 'f')
                {
                    if(!KEY[MAP[mx][my] - 'a']) // 이미 얻은 키가 아닐 경우.
                   { track.push(make_pair(make_pair(mx, my), MAP[mx][my])); // 경로에 넣어줌.
                    KEY[MAP[mx][my] - 'a'] = true;                         // 해당 키를 얻음.
                    memset(check, 0, sizeof(check));                       // 키 얻고 다시탐색.
                    while(!q.empty())
                        q.pop();
                   }
                    q.push(make_pair(mx, my));
                    check[mx][my] = true;
                }
                else if (MAP[mx][my] >= 'A' && MAP[mx][my] <= 'F')
                {
                    if (KEY[MAP[mx][my] - 'A']) // 키가 있는지 체크
                        {
                            q.push(make_pair(mx, my));
                            use_key[MAP[mx][my] - 'A'] = true; // ㅋㅣ 사용 체크
                            check[mx][my] = true;
                        }
                }
                else if (MAP[mx][my] == '1') // 탈출!
                {
                    answer = 0;
                    track.push(make_pair(make_pair(mx, my), '1'));
                    while (!q.empty())
                        q.pop();
                }
                else
                {
                    check[mx][my] = true;
                    q.push(make_pair(mx, my));
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                cout << check[i][j];
            cout << endl;
        }
        cout << endl;
    }
    if(answer == -1)
    {
        cout << answer << endl;
        return 0;
    }
    int px = track.front().first.first;
    int py = track.front().first.second;
    track.pop();
    while(!track.empty())
    {
        int x = track.front().first.first;
        int y = track.front().first.second;
        char a = track.front().second; // key
        cout << x << " " << y << " " << a << endl;
        track.pop();
        if(a == '1' || use_key[a - 'a']) //사용된 키가 맞는지.
        {
            cout << px << " " << py << " " << x << " " << y << endl;
            answer += bfs(px, py, x, y);
            cout <<"answer " << answer << endl;
            use_key[a - 'a'] = false;// key는 얻으러 두번 갈 필요가 없음.
                px = x;
            py = y;
        }

    }

    cout << answer << endl;
    return 0;
}

int bfs(int a, int b, int c, int d)
{
    // cout << a << " " << b << " " << c << " " << d << endl;
    int check[51][51];
    memset(check, 0, sizeof(check));
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx >= 1 && mx <= n && my >= 1 && my <= m && !check[mx][my] &&MAP[mx][my]!='#')
            {
                check[mx][my] = check[x][y] + 1;
                q.push(make_pair(mx, my));
                if(mx == c && my == d)
                    return check[mx][my];
            }
        }

        //         for(int i=1; i<=n; i++)
        // {
        //     for(int j=1; j<=m; j++)
        //         cout << check[i][j];
        //     cout << endl;
        // }
        // cout << endl;
    }
}