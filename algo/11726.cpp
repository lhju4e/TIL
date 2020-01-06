#include <stdio.h>

int d[1001];
int top(int n);
int bottom(int n);

int main()
{
  int n;
  scanf("%d", &n);
  // printf("%d", bottom(n));
  printf("%d", top(n));
  return 0;
}

int bottom(int n)
{
  d[1] = 1;
  d[2] = 2;
  for(int i=3; i<=n; i++)
    d[i] = (d[i-1] + d[i-2])%10007;
  return d[n];
}

int top(int n)
{
  if(n == 1)
    return 1;
  if(n == 2)
    return 2;
  if(d[n]>0)
    return d[n];
  d[n] = top(n-1) + top(n-2);
  d[n] = d[n] % 10007;
  return d[n];
}