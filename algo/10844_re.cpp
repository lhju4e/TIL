#include <iostream>
using namespace std;
long long dp[101][10];
long long answer = 0;
long long md = 1000000000;
int main()
{
    int n;
    cin >> n;
    dp[1][0] = 0;
    for(int i=1; i<=9; i++)
        dp[1][i] = 1;
    for(int i=2; i<=n; i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        for(int j=1; j<=8; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%md;
    }
    for(int i=0; i<=9; i++)
        answer = (answer + dp[n][i])%md;
    cout << answer;
    return 0;
}