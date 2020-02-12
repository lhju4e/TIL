#include<iostream>
#include <math.h>
using namespace std;
int dp[100001];
int main()
{
  int m;
  cin >> m;
  dp[0] = 0;
  dp[1] = 1;
  for(int i=2; i<=m; i++)
  {
    dp[i] = dp[i-1] + 1;
    for(int j=2; j*j<=i; j++)
    {
      dp[i] = min(dp[i- j*j] + 1, dp[i]);
    }
  }
  cout << dp[m];
  return 0;
}