#include <queue>
#include <stdio.h>
using namespace std;
int map[100][100] = {0};
int check[100][100] = {0};

void bfs(int, int);
int main()
{
  int n, m = 0;
  scanf("%d %d ", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      scanf("%1d", &map[i][j]);
    }


 bfs(n, m);

  printf("%d", check[n-1][m-1]);

  return 0;
}

void bfs(int n, int m)
{
  int x, y = 0;
  int dx, dy = 0;
  int shift_x[5] = {-1, 0, 0, 0, 1};
  int shift_y[5] = {0, 0, 1, -1, 0};

  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  check[0][0] = 1;
  while (!q.empty())
  {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    for (int k = 0; k < 5; k++)
    {
      dx = x + shift_x[k];
      dy = y + shift_y[k];
      if (dx >= 0 && dx < n && dy >= 0 && dy < m)
      {
        if (check[dx][dy] == 0 && map[dx][dy] == 1)
        {
          q.push(make_pair(dx, dy));
          check[dx][dy] = check[x][y] + 1;
        }
      }
    }
  }
}