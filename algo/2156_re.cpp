#include <iostream>
using namespace std;
int grape[10001];
int dp[10001][2];
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> grape[i];
    dp[1][0] = 0;
    dp[1][1] = grape[1];

    for(int i=2; i<=n; i++)
    {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(dp[i-2][0] + grape[i-1], dp[i-2][1]) + grape[i];
    }
    cout << max(dp[n][0] , dp[n][1]);
    return 0;
}