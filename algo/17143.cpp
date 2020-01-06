#include <stdio.h>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;
int map[101][101];
bool check[10001];
vector<tuple<int, int, int, int, int>> shark;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
int main()
{

  // memset(check, false, sizeof(check));
  // memset(map, 0, sizeof(map));
  int R, C, M;
  int result = 0;
  int tmp = 0;
  scanf("%d %d %d", &R, &C, &M);

  int r, c, s, d, z = 0;
  for (int i = 0; i < M; i++)
  {
    scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
    if(d == 2 || d == 1)
      s =  s% ((R-1)*2);
    else
      s = s % ((C-1)*2);
    shark.push_back(make_tuple(z, r, c, s, d)); // 크기, 위치, 속력, 방향
    map[r][c] = z;
    check[z] = true;
  }

  for (int k = 1; k <= C; k++) //낚시꾼 한칸 이동
  {
    for (int i = 1; i <= R; i++)
    {
      if (map[i][k] != 0) //열로 도는데 상어가 있으면
      {
        result += map[i][k];
        check[map[i][k]] = false;
        // printf("kill shark : %d\n", map[i][k]);
        map[i][k] = 0; // 상어는 죽었어
        break;
      }
    }
    for (int i = 0; i < shark.size(); i++)
    {
      tie(z, r, c, s, d) = shark[i];   
     tmp = s;            
      map[r][c] = 0;  // 원래있던 맵 변화
      if (check[z] == true) // 상어가 살아있으면 이동시켜줌
      {
       while(tmp--)
        {
          r = r + dx[d];
          c = c + dy[d];
          if (r == 1 && d == 1)
            d = 2;
          if (r == R && d == 2)
            d = 1;
          if (c == 1 && d == 4)
            d = 3;
          if (c == C && d == 3)
            d = 4;
        }

        shark[i] = tie(z, r, c, s, d); // 상어정보변환
        // printf("%d-th shark :  %d %d %d %d\n", z, r, c, s, d);
      }
    }
    //만약에 상어끼리 만나면
    //잡아먹음 - 상어좌표 동시에 이동
    for (int i = 0; i < shark.size(); i++)
    {
      tie(z, r, c, s, d) = shark[i];
      if (check[z] == true)
      {
        if (map[r][c] != 0)
        {
          if (z > map[r][c])
          {
            check[map[r][c]] = false;
            map[r][c] = z;
          }
          else
            check[z] = false;
        }
        else
          map[r][c] = z;
      }
    }
    // printf("===============================\n");
    //     for (int i = 1; i <= R; i++)
    // {
    //   for (int j = 1; j <= C; j++)
    //     printf("%d ", map[i][j]);
    //   printf("\n");
    // }
   // printf("result : %d\n", result);
  }
  printf("%d", result);
  return 0;
}