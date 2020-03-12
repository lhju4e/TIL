#include <iostream>
#include <queue>
using namespace std;
int tom[1001][1001];
bool check[1001][1001];
int shift_x[4]= {-1, 0, 1, 0};
int shift_y[4]= {0, 1, 0, -1};
int main()
{
    queue<pair<int, int>> q;
    int m, n;
    int ans=0;
    cin >> m >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            {
                cin >> tom[i][j];
                if(tom[i][j] == 1)
                    {
                        q.push(make_pair(i, j));
                        check[i][j] = true;
                    }
                if(tom[i][j] == -1)
                    {
                        check[i][j] = true;
                    }
            }
    int x, y, dx, dy;
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++)
        {
            dx = x + shift_x[k];
            dy = y + shift_y[k];
            if(check[dx][dy] == false && dx>=1 && dy>=1 && dx<=n && dy<=m)
            {
                tom[dx][dy] = tom[x][y] + 1;
                check[dx][dy] = true;
                q.push(make_pair(dx, dy));
            }
        }
    }
        // for(int i=1; i<=n; i++)
        // {
        // for(int j=1; j<=m; j++)
        //     cout << tom[i][j] << " ";
        // cout << endl;
        // }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(tom[i][j] == 0)
            {
                cout << "-1";
                return 0;
            }
            if(tom[i][j]>ans)
                ans = tom[i][j];
        }
    }
    cout << ans-1;



    return 0;
}