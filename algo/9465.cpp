#include <iostream>
using namespace std;
int a[100001][2];
int dp[100001][3];
int main()
{
    int t, n;
    int ans;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n;
        for(int l=0; l<2; l++)
            for(int j=1; j<=n; j++)
                cin >> a[j][l];
        
        dp[1][0] = a[1][0];
        dp[1][1] = a[1][1];
        dp[1][2] = 0;
        for(int j=2; j<=n; j++)
        {
            dp[j][0] = max(dp[j-1][2], dp[j-1][1]) + a[j][0];
            dp[j][1] = max(dp[j-1][0], dp[j-1][2]) + a[j][1];
            dp[j][2] = max(max(dp[j-1][0], dp[j-1][1]), dp[j-1][2]);
        }
        ans = max(max(dp[n][0], dp[n][1]), dp[n][2]);
        cout << ans << endl;
    }
    return 0;
}