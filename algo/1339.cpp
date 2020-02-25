#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    int n;
    vector<char> v[10];

    cin >> n;
    string a[10];
    map<char, int> m;
    int k = 9;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        for(int j=a[i].length()-1; j>=0; j--)
        {
            v[j].push_back(a[i].at(a[i].length()-j-1));
        }    
    }
    for(int i=9; i>=0; i--)
    {
        if(!v[i].empty())
        {
            for(int j=0; j<v[i].size(); j++)
            {
                if(m.count(v[i][j]) != 0)
                    continue;
                m.insert(make_pair(v[i][j], k));
                k--;
            }
        }
    }
    double ans = 0; // int형으로 했더니 자꾸 이상하게 빼짐.!!!
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<a[i].length(); j++)
        {
            
            // cout << a[i][j] << " " << m.find(a[i][j])->second << endl;
            // cout << "pow(10, a[i].length() - j - 1) " << pow(10, a[i].length() - j - 1) << endl;
            // cout << "((m.find(a[i][j])->second) * pow(10, a[i].length() - j - 1)) " << ((m.find(a[i][j])->second) * pow(10, a[i].length() - j - 1)) << endl;


            ans += ((m.find(a[i][j])->second) * pow(10, a[i].length() - j - 1))  ;

            
            // cout << "ans " << ans << endl;
        }   
    }
    cout << ans;
    return 0;
}