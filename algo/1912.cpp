#include <iostream>
#include <math.h>
using namespace std;
int dp[100001];
int n[100001];
int main()
{
  int m;
  cin >> m;
  for(int i=1; i<=m; i++)
    cin >> n[i];
  dp[1] = n[1];
  int mm = dp[1];


  for(int i=2; i<=m; i++)
  {
    dp[i] = max(dp[i-1] + n[i], n[i]);
    // cout << dp[i-1] + n[i] << " " << n[i] << endl;
    mm = max(mm, dp[i]);
  }
  cout << mm;
  return 0;
}