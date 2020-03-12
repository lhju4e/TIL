#include <stdio.h>
#include <queue>
using namespace std;
int boad[10][10];
int main()
{
    bool check = false;
    int cnt = 0;
    int ans = -1;
    int n, m;
    int x, y, bx, by;
    int dx, dy, bdx, bdy;
    int shift_x[4] = {-1, 1, 0, 0};
    int shift_y[4] = {0, 0, 1, -1};
    // pair<int, int> red;
    // pair<int, int>blue;
    pair<int, int>goal;
    queue<pair<int, int>> red;
    queue<pair<int, int>> blue;
    char tmp;
    scanf("%d %d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &tmp);
            if (tmp == '#')
                boad[i][j] = -1;
            else if (tmp == '.')
                boad[i][j] = 0;
            else if (tmp == 'O')
                goal = make_pair(i, j);
            else if (tmp == 'R')
                {red.push(make_pair(i, j));
                boad[i][j] = 1;}
            else if (tmp == 'B')
                blue.push(make_pair(i, j));
        }
        getchar();
    }
    while (!red.empty())
    {
        if(cnt >10)
        {
            printf("-1");
            return 0;
        }
           for(int i=0; i<n; i++)
        {for(int j=0; j<m; j++)
            printf("%2d", boad[i][j]);
            printf("\n");
        } 
        cnt++;
        x = red.front().first;
        y = red.front().second;
        red.pop();
        bx = blue.front().first;
        by = blue.front().second;
        blue.pop();

        for (int i = 0; i < 4; i++)
        {
            check = false;
            dx = x + shift_x[i];
            dy = y + shift_y[i];
            bdx = bx + shift_x[i];
            bdy = by + shift_y[i];
            if (boad[dx][dy] == 0 )
            {
                while (boad[dx][dy] != -1)
                {
                             
                    if (dx == bx && dy == by) // 빨간공 가는길에 파란공이 있으면
                    {
                        check = true;
                        if (dx == goal.first && dy == goal.second) // 그리고 그 길이 골이라면
                        {
                            printf("-1");
                            return 0;
                        }
                    }
                    if(dx == goal.first && dy == goal.second) // 골이라면
                        ans = cnt;

                    boad[dx][dy] = cnt;
                    dx += shift_x[i];
                    dy += shift_y[i];    
                }
                if (check)
                { // 빨간공 한칸 물러나고 그자리에 파란공이 온다.
                    bdx = dx;
                    bdy = dy;
                    dx -= shift_x[i];
                    dy -= shift_y[i];
                }
                else // 아니라면 파란공도 끝까지 밀어줌.
                {
                    while (boad[bdx][bdy] != -1 && (bdx != dx && bdy != dy))
                    {
                       if (bdx == goal.first && bdy == goal.second)
                        {
                            printf("-1");
                            return 0;
                        } 
                        bdx += shift_x[i];
                        bdy += shift_y[i];
                    }
                }
                dx -= shift_x[i];
                dy -= shift_y[i];
                bdx -= shift_x[i];
                bdy -= shift_y[i];
                if(ans != -1)
                {
                    printf("%d", ans);
                    return 0;
                }
                if(dx == x && dy == y)
                    continue;
                red.push(make_pair(dx, dy));
                blue.push(make_pair(bdx, bdy));
            }
        }

    }
    return 0;
}