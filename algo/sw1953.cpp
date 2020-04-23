#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int MAP[50][50];
int check[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1}; 
int main()
{
    int test;
    int n, m, r, c, l;
    cin >> test;
    for(int t=1; t<=test; t++)
    {
        memset(MAP, 0, sizeof(MAP));
        memset(check, 0, sizeof(check));
        cin >> n >> m >> r>> c >> l;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> MAP[i][j];
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        check[r][c] = true;

        int cnt = 0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            // cout << "x " << x << " y " << y << endl;
            q.pop();
            cnt++;

            //위 검사
            if(MAP[x][y] == 1 || MAP[x][y] == 2||MAP[x][y] == 4||MAP[x][y] == 7) 
            {
                int mx = x + dx[0];
                int my = y + dy[0];
                if(!check[mx][my] && (MAP[mx][my] ==1 || MAP[mx][my] ==2||MAP[mx][my] ==5||MAP[mx][my] ==6))
                {
                    check[mx][my] = check[x][y]+1;
                    if(check[mx][my]<=l)
                        q.push(make_pair(mx, my));
                }
            }

            //아래 검사
            if(MAP[x][y] == 1 || MAP[x][y] == 2||MAP[x][y] == 5||MAP[x][y] == 6) 
            {
                int mx = x + dx[1];
                int my = y + dy[1];
                if(!check[mx][my] && (MAP[mx][my] ==1 || MAP[mx][my] ==2||MAP[mx][my] ==4||MAP[mx][my] ==7))
                {
                    check[mx][my] = check[x][y]+1;
                    if(check[mx][my]<=l)
                        q.push(make_pair(mx, my));
                }
            }
            //오른쪽 검사
            if(MAP[x][y] == 1 || MAP[x][y] == 3||MAP[x][y] == 4||MAP[x][y] == 5) 
            {
                int mx = x + dx[2];
                int my = y + dy[2];
                if(!check[mx][my] && (MAP[mx][my] ==1 || MAP[mx][my] ==3||MAP[mx][my] ==6||MAP[mx][my] ==7))
                {
                    check[mx][my] = check[x][y]+1;
                    if(check[mx][my]<=l)
                        q.push(make_pair(mx, my));
                }
            }
            //왼쪽 검사
            if(MAP[x][y] == 1 || MAP[x][y] == 3||MAP[x][y] == 6||MAP[x][y] == 7) 
            {
                int mx = x + dx[3];
                int my = y + dy[3];
                if(!check[mx][my] && (MAP[mx][my] ==1 || MAP[mx][my] ==3||MAP[mx][my] ==4||MAP[mx][my] ==5))
                {
                    check[mx][my] = check[x][y]+1;
                    if(check[mx][my]<=l)
                        q.push(make_pair(mx, my));
                }
            }
        }
        cout << "#" <<t<< " " <<cnt << endl;
    }

}