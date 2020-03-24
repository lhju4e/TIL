#include <iostream>
using namespace std;
int dp[1001][1001];
int max(int, int);
int main()
{
    int MAP[1001][1001];
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> MAP[i][j];
    dp[0][0] = MAP[1][1];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int tmp = MAP[i][j];
            if(i-1 >=0 && j-1>=0)
            {
                tmp = max(tmp, MAP[i-1][j-1]);
                tmp = max(tmp, MAP[i][j-1]);
                tmp = max(tmp, MAP[i-1][j]);
            }
                
            MAP[i][j] = max(MAP[i-1][j-1], MAP[i][j-1], MAP[i-1][j]);
        }
    }

}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}