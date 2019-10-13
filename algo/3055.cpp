#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
char s[50][50];
int map[50][50] = {
    0,
};
int move_map[50][50] = {
    0,
};
bool check[50][50] = {
    false,
};
  int r, c;
  int start_x, start_y;
  int end_x, end_y;
  int sx[4] = {-1, 1, 0, 0};
  int sy[4] = {0, 0, 1, -1};
  queue<pair<int, int>> q;
  queue<pair<int, int>> moveq;

void water_bfs();
void bfs();
int main()
{

  scanf("%d %d", &r, &c);
  getchar();
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      scanf("%1c", &s[i][j]);
      if (s[i][j] == 'X')
      {
        map[i][j] = -1;
        move_map[i][j] = -1;
      }
      if (s[i][j] == 'D')
      {
        end_x = i;
        end_y = j;
        map[i][j] = -1;
      }
      if (s[i][j] == 'S')
      {
        start_x = i;
        start_y = j;
        moveq.push(make_pair(i, j));
        move_map[i][j] = 1;
      }
      if (s[i][j] == '*')
      {
        q.push(make_pair(i, j));
        check[i][j] = true;
        map[i][j] = 1;
        move_map[i][j] = -1;
      }
    }
    getchar();
  }
water_bfs();
  memset(check, false, sizeof(check));
  check[start_x][start_y] = true;
bfs();


  //     for(int i=0; i<r; i++)
  //     {for(int j=0; j<c; j++)
  //       printf("%d", map[i][j]);
  //       printf("\n");
  // }
  // printf("===========\n");
  //     for(int i=0; i<r; i++)
  //     {for(int j=0; j<c; j++)
  //       printf("%d", move_map[i][j]);
  //       printf("\n");
  // }
}

void water_bfs()
{
  while (!q.empty())
  {
    int next_x = q.front().first;
    int next_y = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++)
    {
      int dx = next_x + sx[k];
      int dy = next_y + sy[k];
      if (dx >= 0 && dy >= 0 && dx < r && dy < c)
        if (map[dx][dy] = -1 && check[dx][dy] == false)
        {
          map[dx][dy] = map[next_x][next_y] + 1;
          check[dx][dy] = true;
          q.push(make_pair(dx, dy));
        }
    }
  }
}

void bfs()
{
  while (!moveq.empty())
  {
    int x = moveq.front().first;
    int y = moveq.front().second;
    moveq.pop();
    for (int k = 0; k < 4; k++)
    {
      int dx = x + sx[k];
      int dy = y + sy[k];
      if (dx == end_x && dy == end_y)
      {
        printf("%d", move_map[x][y]); // 원래 다음칸이니까 1빼줘야하는데, 시간을 셀 때 0부터 안세고 1부터 셈
        return;                     //         return 0;
      }
      if (dx >= 0 && dy >= 0 && dx < r && dy < c)
        if (move_map[dx][dy] == 0 && check[dx][dy] == false && ((move_map[x][y] + 1 < map[dx][dy]) || map[dx][dy] == 0))
        {
          move_map[dx][dy] = move_map[x][y] + 1;
          check[dx][dy] = true;
          moveq.push(make_pair(dx, dy));
        }
    }
  }

  printf("KAKTUS\n");

}