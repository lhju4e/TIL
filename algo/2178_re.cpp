#include <queue>
#include <stdio.h>
using namespace std;

void bfs(int n, int m);
int maze[101][101];
int check[101][101];

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n;i++)
    for(int j=1; j<=m; j++)
      scanf("%1d", &maze[i][j]);
  bfs(n, m);
  printf("%d", check[n][m]);
  return 0;
}

void bfs(int n, int m)
{
  queue<pair<int, int>> q;
  int _x,_y=0;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};
  q.push(make_pair(1, 1));

  check[1][1] = 1;
  while(!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int k=0; k<4; k++)
    {
      _x = x + dx[k];
      _y = y + dy[k];
      if(_x>=1 && _y>=1 && _x<=n && _y<=m)
      {
        if(check[_x][_y] == 0 && maze[_x][_y] == 1)
        {
          q.push(make_pair(_x, _y));
          check[_x][_y] = check[x][y]+1;
        }
      }
    }
  }
}