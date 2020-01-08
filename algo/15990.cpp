#include <iostream>
using namespace std;
long long dp[100001][4];
long long mod = 1000000009;
int top(int n);
long long bottom(int n);
int main()
{
  int t;
  cin >> t;
  dp[1][1] = 1;
  dp[2][2] = 1;
  dp[3][1] = 1;
  dp[3][2] = 1;
  dp[3][3] = 1;

  for (int i = 0; i < t; i++)
  {
    int n;
    cin >> n;
    cout << bottom(n) << "\n";
  }
  return 0;
}

long long bottom(int n)
{
  if (dp[n][0])
    return dp[n][0];
  if(n==1 || n==2)
    return 1;
  if(n==3)
    return 3;
  for (int i = 4; i <= n; i++)
  {
    dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
    dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
    dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
    dp[i][0] = (dp[i][1] + dp[i][2] + dp[i][3]) % mod;
  }
  return dp[n][0];
}