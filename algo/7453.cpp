#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[4000];
int b[4000];
int c[4000];
int d[4000];
int main()
{
    vector<int> ab;
    vector<int> cd;
    int n;
    int cnt=0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
        cin >> d[i];
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ab.push_back(a[i] + b[j]);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cd.push_back(c[i] + d[j]);
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    int i=0,j=cd.size()-1;
    //ab그룹이 음수고, cd그룹이 양수인 경우
    while(ab[i] < 0 && cd[j] > 0)
    {
        if(ab[i] + cd[j] == 0)
        {
            int c1 = 1;
            int c2 = 1;
            while(i<n-1 && ab[i] == ab[i+1])
            {
                c1++;
            }
            cnt += c1* c2;
        }
    }
    //둘다 0인 경우
    //ab그룹이 양수고, cd그룹이 음수인 경우
    cout << cnt;
    return 0;
}