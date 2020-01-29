#include <stdio.h>
int a[1001];
int d[1001];
int main()
{
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);

  for(int i=1; i<=n; i++)
  {
    int tmp = 0;
    for(int j=0; j<i; j++)
    {
      if(a[j]<a[i] && tmp < d[j])
        tmp = d[j];
    }
       d[i] = tmp + a[i];
  }
  int m = 0;
  for(int i=1; i<=n; i++)
    if(m<d[i])
      m = d[i];
  printf("%d",  m);
  return 0;
}