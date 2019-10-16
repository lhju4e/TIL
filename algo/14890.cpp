#include <stdio.h>
#include <cstring>
int map[100][100] = {
    0,
};
int n, l, result = 0;
bool road(int *);
int main()
{
  scanf("%d %d", &n, &l);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &map[i][j]);
  int tmp[100] = {
      0,
  };

  for (int i = 0; i < n; i++)
  {
    if (road(map[i])) // 가로
       result++;
    for (int j = 0; j < n; j++)
      tmp[j] = map[j][i];
    if (road(tmp)) // 세로
      result++;
    memset(tmp, 0, sizeof(tmp));
  }
  printf("%d", result);
  return 0;
}

bool road(int a[100])
{
  bool check[100] = {false, };
  int cnt = 1;
  for (int i = 0; i < n-1; i++) // 다음수랑 비교하니까 n-1
  {
    if (a[i] == a[i + 1]) // 현재수랑 다음수랑 같고 경사로 설치가 안되어있으면
      {
        if(check[i+1] == false)
          cnt++;
      }
    else if (a[i] - a[i + 1] == 1) // 현재수가 1 더 크면
    {
      int nextCnt = 1;
      if(check[i+1] == true)
        nextCnt--;
      for (int j = i + 1; j < n-1; j++) // 다음수부터 같은 숫자 체크
      {
        if(a[j] == a[j+1])
          {
            if(check[j+1] == false)
              nextCnt++;
          }
        else
          break;
      }
    //  printf("nextCnt : %d\n", nextCnt);
      if(nextCnt>=l) // l보다 같거나 크면
      {
        for(int k=0; k<l; k++) // l개만큼
          check[i+1+k] = true;
      }
      else
        return false;
      cnt = 0;
    }
    else if (a[i] - a[i + 1] == -1) // 다음수가 더 크면
    {
      if(cnt>=l) //현재까지 카운트했던거 계산 및 비교
        {
          for(int k=0; k<l; k++) //l개만큼 체크
            check[i - k] = true;
        }
      else
        return false;
      
      if(check[i+1] == true)
        cnt = 0;
      else
        cnt = 1;
    }
    else // 차이가 1보다 더 크면
      return false;
  }
  return true;
}