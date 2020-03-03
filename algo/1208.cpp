#include <iostream>
using namespace std;
int a[41];
int cnt;
int n, s;
void go(int n, int);
int main()
{
    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> a[i];
    go(0, 0);
    if(s == 0)
        cnt--;
    cout << cnt;
    return 0;
}

void go(int m, int sum)
{
    if(m == n)
    {
        if(sum == s)
            cnt++;
        // cout << m << " " << sum << " " <<  cnt << endl;
                return;

    }
    go(m+1, sum + a[m]);
    go(m+1, sum);
}