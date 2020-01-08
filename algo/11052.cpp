#include <stdio.h>
#include <algorithm>
int p[1001];
bool check[1001];

int top(int n);
int bottom(int n);
int main()
{
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &p[i]);

  check[1] = true;
  // printf("%d", top(n));
  printf("%d", bottom(n));
}

int top(int n)
{
  if(check[n])
    return p[n];

  int tmp;
  for(int i=1; i<=n/2; i++)
    {
      tmp = p[i] + top(n-i);
      p[n] = std::max(tmp, p[n]);
    }
  check[n] = true;
  return p[n];
}

int bottom(int n)
{
  int tmp;
  for(int i=2; i<=n; i++)
  {
    for(int j=1; j<=i/2; j++)
    {
      tmp = p[j] + p[i-j];
      p[i] = std::min(tmp, p[i]);
    }
  }
  return p[n];
}