#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int w[25][25] = {0};
bool check[25][25] = {false}; //이미 갔던 곳이면 true
int bfs(int, int, int);

int main()
{
  int n = 0;
  int tmp = 0;
  vector<int> count;
scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = n - 1; j >= 0; j--)
      scanf("%1d", &w[i][j]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (w[i][j] == 1 && check[i][j] == false) // w[i][j]에 집이 있고 안갔던 곳이면
      {
        count.push_back(bfs(i, j, n));
      }

  sort(count.begin(), count.end());
  printf("%d\n", count.size());
  for (int i = 0; i < count.size(); i++)
    printf("%d\n", count[i]);
    return 0;

}

int bfs(int a, int b, int n)
{
  int x, y = 0;
  int count = 0;
  queue<pair<int, int>> q;

  q.push(make_pair(a, b));
  check[a][b] = true;
  while (!q.empty())
  {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    count++;

    if (x + 1 < n)
      if (w[x + 1][y] == 1 && check[x + 1][y] == false)
      {
        q.push(make_pair(x + 1, y));
        check[x + 1][y] = true;
      }
    if (y + 1 < n)
      if (w[x][y + 1] == 1 && check[x][y + 1] == false)
      {
        q.push(make_pair(x, y + 1));
        check[x][y + 1] = true;
      }
    if (x - 1 >= 0)
      if (w[x - 1][y] == 1 && check[x - 1][y] == false)
      {
        q.push(make_pair(x - 1, y));
        check[x - 1][y] = true;
      }
    if (y - 1 >= 0)
      if (w[x][y - 1] == 1 && check[x][y - 1] == false)
      {
        q.push(make_pair(x, y - 1));
        check[x][y - 1] = true;
      }
  }

  return count;
}