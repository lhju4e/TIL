#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> v;
    string tmp;
    int N, M;
    cin >> N >> M;
    map<string, int> m;
    for(int i=0; i<N; i++)
    {
        cin >> tmp;
        m[tmp]++;
    }
    for(int i=0; i<M; i++)
    {
        cin >> tmp;
        m[tmp]++;
    }
    for(map<string, int>::iterator it = m.begin(); it!= m.end(); it++)
    {
        if(it->second == 2)
        {
            v.push_back(it->first);
        }
    }
    cout << v.size() << endl;
    for(int i=0; i<v.size(); i++)
        cout << v[i] << endl;
    return 0;
}