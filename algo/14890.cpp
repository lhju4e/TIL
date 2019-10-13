#include <stdio.h>
int map[100][100];
bool check(int, int, int);
int result = 0;
int n, l;
int main()
{
  scanf("%d %d", &n, &l);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &map[i][j]);

  for (int i = 0; i < n; i++)
  {
    if (check(i, 0, 1))
    {
      result++;
      printf("row : %d\n", i);
    }
    if (check(0, i, -1))
    {
      result++;
      printf("col : %d\n", i);
    }
  }

  printf("%d", result);
  return 0;
}
bool check(int x, int y, int dir)
{
  bool mark[50] = {
      false,
  };
  int cnt = 0;
  int num = 0;
  int current;
  if (dir == 1) // 가로
  {
          if (mark[y] == false)
      {
        cnt++;
      }
    for (int i = y; i < n -1 ; i++)
    {

      if ((map[x][i] == map[x][i + 1]) && mark[i + 1] == false) //현재거랑 다음거랑 숫자가 같다면
      {
        cnt++;
      }                                        // 그 갯수 카운트
      else if (map[x][i] - map[x][i + 1] == 1) // 현재것이 숫자가 1 더 클때
      {
        current = i; // 현재위치 기억
        cnt = 0;     //cnt 초기화
                  if (mark[i+1] == false)
          {
            cnt++;
          }
        for (int j = i + 1; j < n-1; j++)
        {

          if ((map[x][j] == map[x][j + 1]) && mark[j + 1] == false) //현재거랑 다음거랑 숫자가 같다면
          {
            cnt++;
          } // 그 갯수 카운트
          else
            break;
        }
        if (cnt >= l) //작은것 갯수가 l보다 같거나 크면
        {
          for (int k = 1; k <= l; k++)
            mark[current + k] = true;
          if (check(x, current + 1, dir)) //그 이후 체크 - 체크 전부 통과하면
            break;
          else
            return false;
        }
        else // 작은것 갯수가 l이하이면
          return false;
      }
      else if (map[x][i] - map[x][i + 1] == -1) // 다음것 숫자가 1 더 클때
      {
        // printf("%d %d %d %d %d\n", x, i, l, cnt, dir);
        if (cnt >= l) //cnt가 l이상인지 체크
        {
          if (check(x, i + 1, dir)) // 다음것부터 체크
           break;
          else
            return false;
        }
        else
          return false;
      }
      else // 숫자가 1이상 차이날때
        return false;
    }
  }

  else // 세로
  {
       if (mark[x] == false)
      {
        cnt++;
      }
    for (int i = x; i < n -1 ; i++)
    {
      printf("%d %d %d %d\n", i, y, cnt, dir);

      if (map[i][y] == map[i + 1][y] && mark[i + 1] == false) //현재거랑 다음거랑 숫자가 같다면
      {
        cnt++;              // 그 갯수 카운트
      }
      else if (map[i][y] - map[i + 1][y] == 1) // 현재것이 숫자가 1 더 클때
      {
        current = i; // 현재위치 기억
        cnt = 0;     //cnt 초기화
          if (mark[i+1] == false)
          {
            cnt++;
          }
        for (int j = i + 1; j < n-1; j++)
        {

          if ((map[j][y] == map[j + 1][y]) && mark[j + 1] == false) //현재거랑 다음거랑 숫자가 같다면
          {
            cnt++;
          } // 그 갯수 카운트
          else
            break;
        }
        if (cnt >= l) //작은것 갯수가 l보다 같거나 크면
        {
          for (int k = 1; k <= l; k++)
            mark[current + k] = true;
          // printf("%d %d %d %d\n", current, current+l+1, y, dir);
          if (check(current + 1, y, dir)) //그 이후 체크 - 체크 전부 통과하면
            break;
          else
            return false;
        }
        else // 작은것 갯수가 l이하이면
          return false;
      }
      else if (map[i][y] - map[i + 1][y] == -1) // 다음것 숫자가 1 더 클때
      {
        if (cnt >= l) //cnt가 l이상인지 체크
        {
          if (check(i + 1, y, dir) == false)
            return false;
          else
              break;

        }
        else
          return false;
      }
      else // 숫자가 1이상 차이날때
        return false;
    }
  }
  return true;
}