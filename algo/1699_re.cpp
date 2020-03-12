#include <iostream>
using namespace std;
int dp[100001];
int po = 0;
int main()
{
    int n;
    cin >> n;
    dp[1] = 1;
    po = 2;
    for(int i=2; i<=n; i++)
    {
        if(i % (po * po) == 0)
        {
            dp[i] = 1;
            po++;
            continue;
        }
        dp[i] = dp[i-1] + 1;
 
        for(int j=1; j*j<=i; j++)
        {
            dp[i] = min(dp[i-j*j]+1, dp[i]); 
        }
    }
    cout << dp[n];
    return 0;
}