#include <stdio.h>
#include <tuple>
#include <queue>
using namespace std;

int d[1000][1000];
int c[1000][1000][2];
int main()
{
  int n, m;
  int shiftx[4] = {-1, 0, 0, 1};
  int shifty[4] = {0, 1, -1, 0};
  int x, y, z, dx, dy = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%1d", &d[i][j]);
  queue<tuple<int, int, int>> q;
  q.push(make_tuple(0, 0, 0));
  c[0][0][0] = 1;

  while (!q.empty())
  {
    tie(x, y, z) = q.front();
   // printf("x y z : %d %d %d\n", x, y, z);
    q.pop();

    for (int k = 0; k < 4; k++)
    {
      dx = x + shiftx[k];
      dy = y + shifty[k];

      if (dx >= 0 && dx < n && dy >= 0 && dy < m)
      {
        if (c[dx][dy][z] == 0 && d[dx][dy] == 0) // 안간곳이고 이동가능한곳이면
        {
          q.push(make_tuple(dx, dy, z));
          c[dx][dy][z] = c[x][y][z] + 1;
        }
        else if (d[dx][dy] == 1 && c[dx][dy][1] == 0 && z == 0) //안간곳이고 벽이 있는 곳인데 아직 벽 안뚫었다면
        {
          q.push(make_tuple(dx, dy, 1));
          c[dx][dy][1] = c[x][y][0] + 1;
        }
      }
    }
  }
  //   for (int i = 0; i < n; i++)
  // {  for (int j = 0; j < m; j++)
  //     printf("%d", c[i][j][0]);
  //     printf("\n");}
  // printf("======\n");
  //  for (int i = 0; i < n; i++)
  // {  for (int j = 0; j < m; j++)
  //     printf("%d", c[i][j][1]);
  //     printf("\n");}
  if (c[n - 1][m - 1][0] != 0 && c[n - 1][m - 1][1] != 0)
    printf("%d", min(c[n - 1][m - 1][0], c[n - 1][m - 1][1]));
  else if (c[n - 1][m - 1][0] != 0)
    printf("%d", c[n - 1][m - 1][0]);
  else if (c[n - 1][m - 1][1] != 0)
    printf("%d", c[n - 1][m - 1][1]);
  else
    printf("-1");
  printf("\n");
  return 0;
}