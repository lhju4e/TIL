#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int a[101][101];
int cnt[101];
int main()
{
  memset(a, 0, sizeof(a));
  memset(cnt, 0, sizeof(cnt));
  int r, c, k = 0;
  int result = 0, tmp = 0;
  scanf("%d %d %d", &r, &c, &k);
  int n = 3, m = 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      scanf("%d", &a[i][j]);
  vector<pair<int, int>> numbers;
  while(a[r-1][c-1]!=k)
  {
    result++;
   printf("result : %d %d %d\n", result, m, n);
  //   for (int i = 0; i < m; i++)
  //   {
  //     for (int j = 0; j < n; j++)
  //       printf("%d ", a[i][j]);
  //     printf("\n");
  //   }

    if (m >= n) // 가로줄연산
    {
      for (int i = 0; i < m; i++)
      {
        for (int j = 0; j < n; j++)
          cnt[a[i][j]]++;
        for (int j = 1; j <= 100; j++)
          if (cnt[j] != 0)
            //{
              numbers.push_back(make_pair(cnt[j], j));
            // printf("cnt[%d] : %d\n", j, cnt[j]);}
        memset(cnt, 0, sizeof(cnt));
        sort(numbers.begin(), numbers.end());
        // printf("vector : ======\n");
        // for(int k=0; k<numbers.size(); k++)
        //  { printf("%d-th : %d ", k, numbers[k].first);
        //  printf("%d ", numbers[k].second);}
        //  printf("\n");
        if (tmp < numbers.size() * 2)
          {
            if(numbers.size()>50)
              tmp = 100;
            else
              tmp = numbers.size() * 2;
          }
        for (int j = 0; j < tmp / 2; j++)
        {
          // printf("---------n? %d\n", n);
          if (j < numbers.size())
          {
            a[i][j * 2] = numbers[j].second;
            a[i][j * 2 + 1] = numbers[j].first;
            // printf("numbers[%d] first %d second %d\n", j, numbers[j].first, numbers[j].second);
            // printf("==a[%d][%d] : %d \n", i, j*2, a[i][j*2]);
            // printf("==a[%d][%d] : %d \n", i, j*2+1, a[i][j*2+1]);
          }
          else
           { a[i][j * 2] = 0;
              a[i][j*2+1] = 0;}
        }
        numbers.clear();
      }
      n = tmp;
      tmp = 0;
    }
    else // 세로줄연산
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
          cnt[a[j][i]]++;
        for (int j = 1; j <= 100; j++)
          if (cnt[j] != 0)
            numbers.push_back(make_pair(cnt[j], j));
        memset(cnt, 0, sizeof(cnt));
        sort(numbers.begin(), numbers.end());
      
        if (tmp < numbers.size() * 2)
          {
            if(numbers.size()>50)
              tmp = 100;
            else
              tmp = numbers.size() * 2;
          }
        for (int j = 0; j < tmp / 2; j++)
        {
          if (j < numbers.size())
          {
            a[j * 2][i] = numbers[j].second;
            a[j * 2 + 1][i] = numbers[j].first;
          }
          else
            {a[j*2][i] = 0;
            a[j*2+1][i] = 0;}
        }
        numbers.clear();
      }
      m = tmp;
      tmp = 0;
    }
    if(result>100)
      {printf("-1");
      return 0;}
  }
  printf("%d", result);
  return 0;
}
