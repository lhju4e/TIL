#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

bool check[10000];
int m[10000][2];
int y[4];
int main()
{
    int t;
    int a, b;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        queue<int> q;
        bool end = false;
        memset(check, 0, sizeof(check));
        memset(m, 0, sizeof(m));
        cin >> a>> b;
        check[a] = true;
        q.push(a);
            int tmp =0;
        while(!q.empty() && end == false)
        {
            int x = q.front();
            // cout << "x " << x << endl;
            q.pop();
            y[0] = (x * 2)%10000; // D
            if(x == 0) // S
                y[1] = 9999;
            else
                y[1] = x - 1;
            tmp = x/1000;
            y[2] = (x % 1000)*10 + tmp; // L
            tmp = x/10;
            y[3] = (x % 10)*1000 + tmp; // R

            for(int j=0; j<4; j++)
            {
                if(check[y[j]] == false)
                {
                    // cout << y[j] << " " << j << endl;
                    q.push(y[j]);
                    m[y[j]][0] = j;
                    m[y[j]][1] = x;
                    check[y[j]] = true;
                }
                if(y[j] == b)
                   end = true;
            }
        }
        int k = b;
        vector<string> v;
        while(k != a)
        {
            int s = m[k][0];
            k = m[k][1];
            // cout << k << endl;
            switch (s)
            {
            case 0: 
                v.push_back("D");
                break;
            case 1:
                v.push_back("S");
                break;
            case 2:
                v.push_back("L");
                break;
            case 3:
                v.push_back("R");
                break;
            }
        }
    for(int j=v.size()-1; j>=0; j--)
        cout <<v[j];
    cout<<endl; 
    v.clear();
    }
    return 0;
}