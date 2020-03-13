#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <tuple>
int su[10][10];
bool check[10];
void find(int k);
bool sudocheck(int [10][10]);

int main()
{
  int t=0, k=0;
  scanf("%d", &t);
  for(int i=0; i<t; i++)
  {
    scanf("%d", &k);
    for(int m=1; m<10; m++)
      for(int n=1; n<10; n++)
        scanf("%d", &su[m][n]);
    
    printf("#%d", t+1);
    find(k);
    // for(int m=0; m<k; m++)
    // {
    //   printf(" %d %d %d", );
    // }
  }
}

void find(int k)
{
  using namespace std;
  vector<tuple<int, int, int>> a;
  int tmp1, tmp2;
  //int fk=0; // 찾은 개수
  //1. 행으로 찾기
  for (int i = 1; i < 10; i++)
  {
    memset(check, 0, sizeof(check));
    for (int j = 1; j < 10; j++)
    {
      if (!check[su[i][j]]) // 기본은 false. false라면
        check[su[i][j]] = true;
      else // 값이 중복되었다는 뜻이므로
      {
        a.push_back(make_tuple(i, j, su[i][j])); // 위치, 중복값 넣어줌.
        for (int m = 1; m < 10; m++)
        {
          if (su[i][j] == su[i][m])
          {
            tmp1 = i;
            tmp2 = m;
          }
          if (!check[su[i][m]]) // 한 번 다 돌았는데도 false가 있다면
            a.push_back(make_tuple(tmp1, tmp2, su[i][m]));
        }
      }
    }
  }
  if(a.size() == k * 2)
  {
    if(k ==1)
    {
      su[std::get<0>(a[0])][std::get<1>(a[0])] = std::get<2>(a[0]);
      su[std::get<0>(a[1])][std::get<1>(a[1])] = std::get<2>(a[1]);
      if(sudocheck(su)
      {
        printf("%d %d %d", )
      }
    }
    else if(k ==2)
    {

    }
    else
    {

    }
  }

  memset(check, 0, sizeof(check));
  vector<pair<int, int>> b;

  //2. 열로 찾기
  for (int i = 1; i < 10; i++)
  {
    memset(check, 0, sizeof(check));
    for (int j = 1; j < 10; j++)
    {
      if (!check[su[j][i]])
        check[su[j][i]] = true;
      else
      {
        b.push_back(make_pair(i, j));
        for (int m = 1; m < 10; m++)
          if (su[j][i] == su[m][i])
            b.push_back(make_pair(m, i));
      }
    }
  }

  //3. 그룹으로 찾기
}

bool sudocheck(int a[10][10])
{
  bool check2[10];
  //행검사
  for(int i=1; i<10; i++)
  {
    memset(check2, false, sizeof(check2));
    for(int j=1; j<10; j++)
    {
      if(!check2[a[i][j]]) //false라면
        check2[a[i][j]] = true;
      else
        return false;
    }
  }
  //열검사
    for(int i=1; i<10; i++)
  {
    memset(check2, false, sizeof(check2));
    for(int j=1; j<10; j++)
    {
      if(!check2[a[j][i]]) //false라면
        check2[a[j][i]] = true;
      else
        return false;
    }
  }
  //그룹검사
  for (int i = 0; i < 3; i++)
    {
    for (int j = 0; j < 3; j++)
      {
         memset(check2, false, sizeof(check2));
        for (int m = 1; m < 4; m++)
        {
          for (int n = 1; n < 4; n++)
          {
            if (!check2[a[m + 3*i][n + 3*j]]) //false라면
              check2[a[m + 3*i][n + 3*j]] = true;
            else
              return false;
          }
        }
      }
    }
  return true;
}
