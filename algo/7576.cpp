#include <stdio.h>
#include <queue>
using namespace std;
int tom[1000][1000] = {0};
bool check[1000][1000] = {false};
int result[1000][1000] = {0};
int main()
{
  queue<pair<int, int>> q;
  int shift_x[4] = {-1, 1, 0, 0};
  int shift_y[4] = {0, 0, 1, -1};
  int x, y = 0;
  int dx, dy = 0;
  int n, m = 0;
  int max = 0;
  bool zero_check = false;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &tom[i][j]);
      if (tom[i][j] == 0)
        zero_check = true;
      else if(tom[i][j] == -1)
        result[i][j] = -1;
      else if(tom[i][j] == 1)
        q.push(make_pair(i, j));
    }

  if (zero_check == false) // 만약에 안익은게 안들어오면
  {
    printf("0");
    return 0;
  }


while(!q.empty())
  {
    x = q.front().first;
    y = q.front().second;
   // printf("x y %d %d\n", x, y );
    q.pop();
    for (int k = 0; k < 4; k++)
    {
      dx = x + shift_x[k];
      dy = y + shift_y[k];
      if (dx >= 0 && dx < m && dy >= 0 && dy < n)
      {
        if (check[dx][dy] == false && tom[dx][dy] == 0)
        {
   //       printf("dx dy %d %d\n", dx, dy);
          q.push(make_pair(dx, dy));
          check[dx][dy] = true;
          if(result[dx][dy] != 0)
            {
              if(result[dx][dy] > result[x][y] + 1)
               result[dx][dy] = result[x][y] + 1;
            }
          else
            result[dx][dy] = result[x][y] + 1;
        }
      }

    }
  }

//   for (int i = 0; i < m; i++)
//     {for (int j = 0; j < n; j++)
//       printf("%d ", result[i][j]);
//       printf("\n");
// }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      if (result[i][j] == 0 && tom[i][j] == 0) // 만약에 안익은 것이 있다면
      {
        printf("-1");
        return 0;
      }
      if (result[i][j] > max)
        max = result[i][j];
    }
  printf("%d", max);
  return 0;
}
