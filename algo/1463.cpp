#include <stdio.h>
#include <algorithm>
#include <cstring>
int d[1000001];
void bottom_up(int);
int top_down(int);
int main()
{
  std::memset(d, 0, sizeof(d));
  int n;
  scanf("%d", &n);
  // bottom_up(n);
  printf("%d", top_down(n));
  return 0;
}

void bottom_up(int n)
{
  d[1] = 0;
  int tmp = 0;
  for(int i=2; i<=n; i++)
  {
    d[i] = d[i-1] + 1;
    if(i%2 == 0)
    {
      tmp = d[i/2] + 1;
      d[i] = std::min(tmp, d[i]);
    }
    if(i%3 == 0)
    {
      tmp = d[i/3] + 1;
      d[i] = std::min(tmp, d[i]);
    }
  }
  printf("%d", d[n]);
}

int top_down(int n)
{
  int tmp;
  if(n == 1)
    return 0;
  if(d[n] >0) // 이미 이전에 d[n]을 구했었다면
    return d[n];
  d[n] = top_down(n-1) + 1;
  if(n%2 ==0)
  {
    tmp = top_down(n/2)+1;
    if(d[n]>tmp)
      d[n] = tmp;
  }
  if(n%3 ==0)
  {
    tmp = top_down(n/3)+1;
    if(d[n]>tmp)
      d[n] = tmp;
  }
  return d[n];
}