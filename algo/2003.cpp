#include <iostream>
using namespace std;

int main()
{
    int a[10001];
    int n, m;
    int s = 0;
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n ; i++)
    {
        s = a[i];
        if (s == m)
        {
            cnt++;
            continue;
        }
        else if (s > m)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            s += a[j];
            if (s == m)
            {
                cnt++;
                continue;
            }
            else if (s > m)
                continue;
        }
    }
    cout << cnt;
    return 0;
}