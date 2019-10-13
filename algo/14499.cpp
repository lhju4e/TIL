#include <stdio.h>
int dice[7] = {
    0,
};
int map[20][20];
void change(int);
int main()
{
  int n, m, x, y, k;
  int dir;
  scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &map[i][j]);
  for (int i = 0; i < k; i++)
  {
    scanf("%d", &dir);
    //printf("dir : %d\n", dir);
    if (dir == 1)
    {
      if (y + 1 < m)
      {
        y = y + 1;
        change(1);
        if (map[x][y] == 0)
          map[x][y] = dice[5];
        else
        {

          dice[5] = map[x][y];
          map[x][y] = 0;
        }
        printf("%d\n", dice[6]);
      }
    }
    if (dir == 2)
    {
      if (y - 1 >= 0)
      {
        y -= 1;
        change(2);
        if (map[x][y] == 0)
          map[x][y] = dice[5];
        else
        {

          dice[5] = map[x][y];
          map[x][y] = 0;
        }
        printf("%d\n", dice[6]);
      }
    }
    if (dir == 3)
    {
      if (x - 1 >= 0)
      {
        x -= 1;
        change(3);
        if (map[x][y] == 0)
          map[x][y] = dice[5];
        else
        {

          dice[5] = map[x][y];
          map[x][y] = 0;
        }
        printf("%d\n", dice[6]);
      }
    }
    if (dir == 4)
    {
      if (x + 1 < n)
      {
        x += 1;
        change(4);
        if (map[x][y] == 0)
          map[x][y] = dice[5];
        else
        {

          dice[5] = map[x][y];
          map[x][y] = 0;
        }
        printf("%d\n", dice[6]);
      }
    }
    // for (int i = 1; i < 7; i++)
    //   printf("%d", dice[i]);
    //   printf("\n");
  }
}

void change(int a)
{
  int tmp;
  if (a == 1)
  {
    tmp = dice[3];
    dice[3] = dice[6];
    dice[6] = dice[4];
    dice[4] = dice[5];
    dice[5] = tmp;
  }
  else if (a == 2)
  {
    tmp = dice[5];
    dice[5] = dice[4];
    dice[4] = dice[6];
    dice[6] = dice[3];
    dice[3] = tmp;
  }
  else if (a == 3)
  {
    tmp = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[2];
    dice[2] = dice[6];
    dice[6] = tmp;
  }
  else
  {
    tmp = dice[6];
    dice[6] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[1];
    dice[1] = tmp;
  }
}