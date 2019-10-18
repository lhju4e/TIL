#include <stdio.h>
#include <queue>
#include <cstring>
#include <tuple>
#include <deque>
#include <algorithm>
#include <functional>
using namespace std;
int m[100][100];
bool check[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main()
{
  int t, n = 0;
  int result = 9999999;
  scanf("%d", &t);
  for (int k = 0; k < t; k++)
  {
    scanf("%d", &n);
    memset(m, 0, sizeof(m));
    memset(check, false, sizeof(check));
    result = 9999999;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%1d", &m[i][j]);

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.push(make_tuple(0, 0, 0));
    check[0][0] = true;

    while (!q.empty())
    {
      int x, y, sum = 0;
      tie(sum, x, y) = q.top();
      //printf("sum x y : %d %d %d\n", sum, x, y);
      q.pop();
      if (x == n - 1 && y == n - 1)
      {
        //printf("result x y : %d %d %d\n", sum, x, y);
        if (result > sum)
          result = sum;
      }
      for (int i = 0; i < 4; i++)
      {
        int sx = x + dx[i];
        int sy = y + dy[i];
        if (sx >= 0 && sy >= 0 && sx < n && sy < n && check[sx][sy] == false)
        {
          q.push(make_tuple(sum + m[sx][sy], sx, sy));
          check[sx][sy] = true;
          // printf("sum sx sy : %d %d %d\n", sum, sx, sy);
        }
      }
    }
    printf("#%d %d\n", k + 1, result);
  }
}