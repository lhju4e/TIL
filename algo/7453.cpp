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
    long long cnt=0;
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
    // for(int i=0; i<ab.size(); i++)
    //     cout << ab[i]<<" ";
    // cout<<endl;
    // for(int i=0; i<cd.size(); i++)
    //     cout << cd[i]<<" ";    
    // cout << endl;
    int i=0,j=cd.size()-1;
    //ab그룹이 음수고, cd그룹이 양수인 경우

    while(j>=0 && i<ab.size())
    {
        if(ab[i] + cd[j] == 0)
        {            
        //  cout <<"i " <<i<< " ab[i] " << ab[i] << " j "<< j << " cd[j] " << cd[j] << endl;

            int c1 = 1;
            int c2 = 1;
            while(i<ab.size()-1 && ab[i] == ab[i+1])
            {
                c1++;
                i++;
                // cout << "i " << i << endl;
            }
            while(j>0 && cd[j] == cd[j-1])
            {
                c2++;
                j--;
                // cout << "j " << j << endl;
            }
            i++;j--;
            cnt += (long long)c1* c2;
        }
        else if(ab[i] + cd[j] > 0)
            j--;
        else if(ab[i] + cd[j] < 0)
            i++;
    }
    cout << cnt;
    return 0;
}