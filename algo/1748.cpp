#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, m;
    int ans=0;
    int cnt=0;
    cin >> n;
    m = n;
    while(m!=0)
    {
        m = m / 10;
        cnt++;
    }
    for(int i=1; i<cnt; i++)
    {
        ans += (9 * pow(10, (i-1)))*i;
    }
    int tmp = ((n - pow(10, cnt-1)) + 1) * cnt;
    cout << ans + tmp;
    return 0;
}