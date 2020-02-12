#include<queue>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int map[26][26];
bool check[26][26];
int bfs(int, int, int n);

int main()
{
  int n, cnt=0;
  scanf("%d", &n);
  vector<int> v;

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      scanf("%1d", &map[i][j]);

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
    {
      if(map[i][j] == 1 && check[i][j] == false)
      {
        v.push_back(bfs(i, j, n));
        cnt++;
      }
    }
  
  sort(v.begin(), v.end()); 
  printf("%d\n", cnt);
  for(int i=0; i<v.size(); i++)
    printf("%d\n", v[i]);
  return 0;
}

int bfs(int i, int j, int n)
{
  int cnt = 1;
  int dx, dy = 0;
  int x, y = 0;
  int shift_x[4] = {-1, 0, 0, 1};
  int shift_y[4] = {0, 1, -1, 0};

  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  check[i][j] = 1;

  while(!q.empty())
  {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    for(int k=0; k<4; k++)
    {
      dx = x + shift_x[k];
      dy = y + shift_y[k];
      if(dx<=n && dx>=1 && dy<=n && dy>=1)
      {
        if(map[dx][dy] == 1 && check[dx][dy] == false)
        {
          check[dx][dy] = true;
          cnt++;
          q.push(make_pair(dx, dy));
        }
      }

    }
  }
  return cnt;
}