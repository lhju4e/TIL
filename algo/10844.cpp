#include <stdio.h>
int dp[101][10];
int mod = 1000000000;
int top(int n);
int bottom(int n);
int main()
{
  for(int i=1; i<=9; i++)
    dp[1][i] = 1;

  int n;
  scanf("%d", &n);
  printf("%d", bottom(n));
  return 0;
}

int bottom(int n)
{
  for(int k=2; k<=n; k++)
  {
    for(int i=1; i<=8; i++)
    {
      dp[k][i] = (long long)(dp[k-1][i-1] + dp[k-1][i+1])%mod;
    }
    dp[k][9] = dp[k-1][8];
    dp[k][0] = dp[k-1][1];
  }

  long long sum = 0;
  for(int i=0; i<=9; i++)
    sum += (long long)(dp[n][i] % mod);
 
  sum = sum % mod;
  int tmp = sum;
  return tmp;
}