#include <stdio.h>
long long dp[91][2];
long long bottom(int n);
int main()
{
  dp[1][1] = 1;
  int n;
  scanf("%d", &n);
  printf("%lld", bottom(n));
  return 0;
}

long long bottom(int n)
{
  for(int i=2; i<=n; i++)
  {
    dp[i][0] = dp[i-1][0] + dp[i-1][1];
    dp[i][1] = dp[i-1][0];
  }
  return dp[n][0] + dp[n][1];
}