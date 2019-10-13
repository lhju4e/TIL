#include <stdio.h>
int map[50][50];
bool check[50][50];
int main()
{
  int m, n;
  int cnt = 0;
  scanf("%d %d", &n, &m);

  int x, y, d = 0;
  scanf("%d %d %d", &x, &y, &d);
  cnt++;
  check[x][y] = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &map[i][j]);

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, -1, 0, 1};

  while(1)
  {
    if ((map[x][y + 1] == 1 || check[x][y + 1] == true) && (map[x + 1][y] == 1 || check[x + 1][y] == true) && (map[x - 1][y] == 1 || check[x - 1][y] == true) && (map[x][y - 1] == 1 || check[x][y - 1] == true))
    // 4면이 벽이거나 이미 간 경우
    {
      for (int i = 0; i < 4; i++) // 뒤에 벽이 있는지 체크
      {
        if (d == i)
        {
          if (map[x + dx[i]][y + dy[i]] == 1) //뒤가 벽이라면 - 끝
          {
            printf("%d", cnt);
            return 0;
          }
          else // 벽이 아니라면 뒤로가기
          {
            x = x + dx[i];
            y = y + dy[i];
           
          }
        }
      }
    }

    else
    {
      if (d == 0) // 왼쪽방향 체크
      {
        d = 3;              //방향을 돌린다
        if (map[x][y - 1] != 1 && check[x][y - 1] == false) //아직 안갔고 벽이 아니라면
        {     
          y = y - 1;          // 돌린방향으로 한 칸 전진
          check[x][y] = true; //청소
          cnt++;
        }
      }     
      else if (d == 1)
      {
        d = 0;                                              //방향을 돌린다
        if (map[x - 1][y] != 1 && check[x - 1][y] == false) //아직 안갔고 벽이 아니라면
        {
          x = x - 1;          // 돌린방향으로 한 칸 전진
          check[x][y] = true; //청소
          cnt++;
        }
      }     
      else if (d == 2)
      {
        d = 1;                                              //방향을 돌린다
        if (map[x][y + 1] != 1 && check[x][y + 1] == false) //아직 안갔고 벽이 아니라면
        {
          y = y + 1;          // 돌린방향으로 한 칸 전진
          check[x][y] = true; //청소
          cnt++;
        }
      }     
      else if (d == 3)
      {
        d = 2;                                              //방향을 돌린다
        if (map[x + 1][y] != 1 && check[x + 1][y] == false) //아직 안갔고 벽이 아니라면
        {
          x += 1;             // 돌린방향으로 한 칸 전진
          check[x][y] = true; //청소
          cnt++;
        }
      }   
    }
  }
}
