#include <iostream>
#include <queue>
int check[100001];
using namespace std;
queue<int> q;
int main()
{
    int n, k;
    int y[3] = {0, 0, 0};
    int ret = 0;
    int cnt = 0;
    int ans = 100001;
    cin >> n >> k;
    if(n==k)
    {cout<<"0"<<endl<<"1"<<endl;
    return 0;}

    q.push(n);
    check[n] = cnt;


    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << "x " << x << " cnt " << check[x] << endl;

        y[0] = x + 1;
        y[1] = x - 1;
        y[2] = x * 2;

        cnt = check[x];
        if (cnt >= ans)
            break;
        for(int i=0; i<3; i++)
        {
            if(y[i] >=0 && y[i] <= 100000 && !check[y[i]])
            {
                if(y[i] == k)
                {
                    ret += 1;
                    ans = cnt + 1;
                }
                else
                {
                    check[y[i]] = cnt + 1;
                    q.push(y[i]);
                }
                
            }
            check[k] = 0;
        }
    }
    cout << ans << endl;
    cout << ret;
    return 0;
}