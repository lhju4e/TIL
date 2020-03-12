#include <iostream>
using namespace std;
int gcd(int, int);
int main()
{
    int n, m, x, y;
    int g;
    int t;
    bool check;
    cin >> t;
    for(int j=0; j<t; j++)
    {
        check = false;
        cin >> m >> n >> x >> y;
        for(int i=0; i<=m; i++)
        {
            if((m*i + x)%n == (y%n))
            {
                cout << (m*i + x) << endl;
                check = true;
                break;
            }
        }
        if(!check)
            cout << -1 << endl;
    }

    return 0;
}
