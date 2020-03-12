#include <iostream>
using namespace std;
int dp[1001];
int p[1001];
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> p[i];
    
    dp[0] = 0;
    dp[1] = p[1];
    for(int i=2; i<=n; i++)
    {
        int m = 10000001;
        for(int j=0; j<=i/2; j++)
        {
            m = min(p[j] + p[i-j], m);
        }
        dp[i] = m;
        p[i] = dp[i];
    }
    cout << dp[n];
    return 0;
}