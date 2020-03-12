#include <iostream>
#include <queue>
#include <vector>
#define N 100001
using namespace std;
// int N = 100001;
bool check[N];
int m[N];
queue<int> v;
int y[3];
int main()
{
    int n, k;
    cin >> n >> k;
    if(n == k)
    {
        cout << "0"<<endl;
        cout << n;
        return 0;
    }
    int x = 0;
    v.push(n);
    check[n] = true;
    bool end = false;
    int cnt = 0;
    while(!v.empty() && end == false)
    {
        x = v.front();
        v.pop();
    
        y[0] = 2*x;
        y[1] = x+1;
        y[2] = x-1;

        for(int i=0; i<3; i++)
        {
            if(y[i]>=0 && y[i]<N && check[y[i]] == false)
            {
                v.push(y[i]);
                m[y[i]] = x;
                check[y[i]] = true;
            }
            if(y[i] == k)
                end = true;
        }  
    }

    int a = k;
    vector<int> path;
    while(a!=n)
    {
        path.push_back(a);
        a = m[a];
    }
    path.push_back(n);
    cout << path.size()-1 << endl;  
    for(int i=path.size()-1; i>=0; i--)
        cout << path[i] << " ";
    return 0;
}