#include <stdio.h>

int dp[1001][10];
int top(int n);

int main()
{
  int n;
  scanf("%d", &n);
  printf("%d", top(n));
}

int top(int n)
{
  for(int i=0; i<=9; i++)
    dp[0][i] = 1;
  for(int i=1; i<=n; i++)
  {
    dp[i][9] = 1;
    for(int j=8; j>=0; j--)
    {
      dp[i][j] = (dp[i][j+1] + dp[i-1][j])%10007;
    }
  }
  return dp[n][0];
}