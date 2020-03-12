#include <iostream>
using namespace std;
long dp1[100001];
long dp2[100001];
long dp3[100001];
int check[100001];
int main()
{
    dp1[1] = 1;
    dp2[2] = 1;
    dp1[3] = dp2[3] = dp3[3] = 1;
    check[1] = check[2] = 1;
    check[3] = 3;
    int n;
    int t;
    long tmp;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n;
        for(int j=4; j<=n; j++)
        {
            if(check[j])
                continue;
            dp1[j] = (dp2[j-1] + dp3[j-1])%1000000009;
            dp2[j] = (dp1[j-2] + dp3[j-2])%1000000009;
            dp3[j] = (dp1[j-3] + dp2[j-3])%1000000009;
            tmp = (dp1[j] + dp2[j])%1000000009;
            check[j] = (long)(dp3[j] + tmp)%1000000009;
        }
        cout << check[n] << endl;
    }
    return 0;
}