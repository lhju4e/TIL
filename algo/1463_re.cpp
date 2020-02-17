#include <iostream>
using namespace std;
int dp[1000001];
int main()
{
    int n;
    cin >> n;
    dp[1] = 0;
    for(int i=2; i<=n; i++)
    {
    if(i%3 ==0 && i%2 ==0)
    {
        int tmp = min(dp[i/3], dp[i/2]);
        tmp = min(tmp, dp[i-1]);
        dp[i] =  tmp + 1;
    }
    else if(i%3==0)
        dp[i] = min(dp[i/3], dp[i-1])+1;
    else if(i%2 ==0)
        dp[i] = min(dp[i/2], dp[i-1])+1;
    else
        dp[i] = dp[i-1] + 1;
    }
    cout << dp[n];
    return 0;
}