#include <iostream>
#include <vector>
using namespace std;

int main()
{
bool check[4000001];    
    vector<int> v;
    int n;
    cin >> n;

    for(int i=2; i<=n; i++)
    {
        if(!check[i])
            v.push_back(i);
        for(int j= 2*i; j<=n; j+=i)
            check[j] = true;
    }
    v.push_back(0); // 밑에서 할당된 크기보다 한 칸 더 참조함.
    int i=0; // 시작
    int j = 0; // 끝
    int s = 0;
    int cnt = 0;
    while(i<=j && j<=v.size())
    {
        if(s < n)
        {
            s += v[j];
            j++;
        }
        else
        {
            if(s == n)
            {
                cnt++;
                // cout << i<< " " << j << " " << s<<endl;
                // cout << v[i] << " " << v[j] << " " << s << endl;
            }
                // cnt++;
            s -= v[i];
            i++;
        }
    }
    cout << cnt;
    return 0;
}