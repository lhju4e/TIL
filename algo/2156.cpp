#include <iostream>
#include <math.h>
int bottom(int);
using namespace std;
int dp[10001];
int a[10001];
int main()
{
 int n;
 cin >> n;
 for(int i=1; i<=n; i++)
   cin >> a[i];
  cout << bottom(n);
}

int bottom(int n)
{
  dp[1] = a[1];
  dp[2] = a[1] + a[2];
  if(n<3)
    return dp[n];
  for(int i=3; i<n+1; i++)
  {
    dp[i] = max(dp[i-3]+a[i]+a[i-1] ,max(dp[i-1], (a[i]+dp[i-2])));
  }
  return dp[n];
}