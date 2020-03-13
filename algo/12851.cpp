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
<<<<<<< HEAD
    if (n == k)
    {
        cout << "0" << endl
             << "1" << endl;
        return 0;
    }
=======
    if(n==k)
    {cout<<"0"<<endl<<"1"<<endl;
    return 0;}
>>>>>>> 7da29d321cd4f762ec37b832c3905c5f953226a9

    q.push(n);
    check[n] = cnt;

<<<<<<< HEAD
=======

>>>>>>> 7da29d321cd4f762ec37b832c3905c5f953226a9
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
<<<<<<< HEAD
        // cout << "x " << x << " cnt " << check[x] << endl;
=======
        cout << "x " << x << " cnt " << check[x] << endl;
>>>>>>> 7da29d321cd4f762ec37b832c3905c5f953226a9

        y[0] = x + 1;
        y[1] = x - 1;
        y[2] = x * 2;

        cnt = check[x];
        if (cnt >= ans)
            break;
<<<<<<< HEAD
        for (int i = 0; i < 3; i++)
        {
            if (y[i] >= 0 && y[i] <= 100000 && (!check[y[i]] || check[y[i]] == cnt+1))
            {
                if (y[i] == k)
                {
                    ret += 1;
                    ans = cnt + 1;
                    // cout << "y[i] " << y[i] << " ans " << ans << " ret " << ret << endl;
=======
        for(int i=0; i<3; i++)
        {
            if(y[i] >=0 && y[i] <= 100000 && !check[y[i]])
            {
                if(y[i] == k)
                {
                    ret += 1;
                    ans = cnt + 1;
>>>>>>> 7da29d321cd4f762ec37b832c3905c5f953226a9
                }
                else
                {
                    check[y[i]] = cnt + 1;
                    q.push(y[i]);
                }
<<<<<<< HEAD
            }
=======
                
            }
            check[k] = 0;
>>>>>>> 7da29d321cd4f762ec37b832c3905c5f953226a9
        }
    }
    cout << ans << endl;
    cout << ret;
    return 0;
}