#include <stdio.h>
#include <queue>
using namespace std;
int map[101][101] = {0,}; //1 - n까지 사용할 것.
int main()
{
  int n, k, l, cnt = 0;
  int x, y, t = 0;
  int lr = 2; // 뱀 이동 방향
  char dir[101] = {0,}; // 뱀 회전방향
  int l_arr[101] = {0,}; // 몇초뒤에 회전할지
  int arr_count = 0; // l_Arr count
  int sx, sy = 0; // 뱀의 머리위치
  queue<pair<int, int>> snake;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {-1, 0, 1, 0};
  scanf("%d %d", &n, &k);
  for(int i=0; i<k; i++)
    {
      scanf("%d %d", &x, &y); //사과좌표
      map[x][y] = 1;
    }
  scanf("%d", &l);
  for(int i=0; i<l; i++)
    scanf("%d %c", &l_arr[i], &dir[i]);

  sx=1; sy=1;
  map[1][1] = 2;
  snake.push(make_pair(1, 1));
  while(1)
  {
    // for(int i=1; i<=n; i++)
    //   {for(int j=1; j<=n; j++)
    //     printf("%d", map[i][j]);
    //     printf("\n");}
    // printf("----------------\n");
    cnt++;
    lr = lr % 4;
    sx = sx +  dx[lr];
    sy = sy +  dy[lr];
    if(sx >n || sy > n || sx <= 0 || sy <= 0 || map[sx][sy] == 2) //범위밖이거나 몸통만나면
    {
      printf("%d", cnt);
      return 0; //함수 끝
    }
    if(map[sx][sy] == 1) // 머리가 움직인 곳에 사과가 있으면
    {
      map[sx][sy] = 2; // 머리만 늘림
      snake.push(make_pair(sx, sy));
    }
    else // 사과 없으면
    {
      int x = snake.front().first;
      int y = snake.front().second;
      snake.pop();
      map[x][y] = 0;
      map[sx][sy] = 2;
      snake.push(make_pair(sx, sy));
    }
    if(arr_count < l && l_arr[arr_count] == cnt)
    {
      if(dir[arr_count] == 'D')
        lr += 1;
      else if(dir[arr_count] == 'L')
        {lr -= 1;
        lr += 4;}
      arr_count++;
    }
  }
  
}