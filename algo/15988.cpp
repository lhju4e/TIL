#include <stdio.h>

int d[1000001];
int top(int);
int bottom(int);

int main()
{
  int t, n;
  d[1] = 1;
  d[2] = 2;
  d[3] = 4;

  scanf("%d", &t);
  for(int i=0; i<t; i++)
  {
    scanf("%d", &n);
   printf("%d\n", top(n));
    //printf("%d\n", bottom(n));
  }
  return 0;
}

int top(int n)
{
  if(d[n]>0)
    return d[n];
  d[n] = (top(n-1) + top(n-2)%1000000009) + top(n-3)%1000000009;
  return d[n];
}

int bottom(int n)
{
  for(int i=4; i<=n; i++)
    d[i] = ((d[i-1] + d[i-2])%1000000009 + d[i-3])% 1000000009;
  return d[n];
}