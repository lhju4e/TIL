#include <iostream>
using namespace std;
int dp[1001][1001];
int MAP[1001][1001];
int max(int, int);
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> MAP[i][j];
    dp[0][0] = MAP[0][0];
     //0행 0열 처리
    for(int i=1; i<n; i++)
        dp[i][0] = MAP[i][0] + dp[i-1][0];
    for(int i=1; i<m; i++)
        dp[0][i] = MAP[0][i] + dp[0][i-1];
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            int tmp = max(dp[i-1][j], dp[i][j-1]);
            tmp = max(dp[i-1][j-1], tmp);
            dp[i][j] = tmp + MAP[i][j];
            // cout <<"i " <<i<<" j " <<j << " "<< dp[i][j]<<endl;
        }
    }
    cout << dp[n-1][m-1];
    return 0;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}