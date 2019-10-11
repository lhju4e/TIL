#include <stdio.h>
#include <deque>
using namespace std;
int main()
{
  int n, m;
  int x, y, dx, dy = 0;
  int shift_x[4] = {-1, 0, 0, 1};
  int shift_y[4] = {0, 1, -1, 0};
  int maze[101][101] = {0};
  int count[101][101] = {0};
  bool check[101][101] = {false};
  scanf("%d %d", &m, &n);
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      scanf("%1d", &maze[i][j]);

  deque<pair<int, int>> dq;
  dq.push_back(make_pair(0, 0));

  while(!dq.empty())
  {
    x = dq.front().first;
    y = dq.front().second;
    dq.pop_front();

    for(int k=0; k<4; k++)
    {
      dx = x + shift_x[k];
      dy = y + shift_y[k];
      if(dx>=0 && dx<n && dy>=0 && dy<m && check[dx][dy] == false)
      {
        if(maze[dx][dy] == 0) // 벽 안뚫는경우
          {
            dq.push_front(make_pair(dx, dy));
            check[dx][dy] = true;
            count[dx][dy] += count[x][y];
          }
        else if(maze[dx][dy] == 1) //벽뚫는경우
        {
          dq.push_back(make_pair(dx, dy));
          count[dx][dy] += count[x][y] + 1;
          check[dx][dy] = true;
        }
      }
    }
  }

  printf("%d", count[n-1][m-1]);

}