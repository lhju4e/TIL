#include <stdio.h>
int d[1001];
int top(int);
int bottom(int);

int main()
{
  int n;
  scanf("%d", &n);
  // printf("%d", top(n));
  printf("%d", bottom(n));
}

int top(int n)
{
  if(n == 1)
    return 1;
  if(n ==2)
    return 3;
  if(d[n] >0)
    return d[n];
  d[n] = top(n-1) + 2*top(n-2);
  d[n] = d[n] % 10007;
  return d[n];
}

int bottom(int n)
{
  d[1] = 1;
  d[2] = 3;
  for(int i=3; i<=n; i++)
    d[i] = (d[i-1] + 2*d[i-2])%10007;
  return d[n];
}
