#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> v;
    int N;
    cin >> N;
    map<string, pair<int, int>> m;
    for (int i = 0; i < N * (N - 1); i++)
    {
        string team1, team2;
        int set1, set2;
        cin >> team1 >> set1 >> team2 >> set2;
        int win1, win2;
        if (set1 < set2)
        {
            win2 = 1;
            win1 = 0;
        }
        else
        {
            win1 = 1;
            win2 = 0;
        }
        if (m.find(team1) == m.end()) // 팀이 없으면 새로 삽입
            m.insert(make_pair(team1, make_pair(win1, set1 - set2)));
        else
        {
            m.find(team1)->second.second += (set1 - set2);
            m.find(team1)->second.first += win1;
        }

        if (m.find(team2) == m.end()) // 팀이 없으면 새로 삽입
            m.insert(make_pair(team2, make_pair(win2, set2 - set1)));
        else
        {
            m.find(team2)->second.second += (set2 - set1);
            m.find(team2)->second.first += win2;
        }
        
    }
    for(auto i = m.begin(); i!= m.end(); i++)
        v.push_back(i->first);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N-1-i; j++)
        {
            if(m.find(v[j])->second.first < m.find(v[j+1])->second.first)
            {
                string tmp = v[j+1];
                v[j+1] = v[j];
                v[j] = tmp;
            }
            else if(m.find(v[j])->second.first == m.find(v[j+1])->second.first) // 숭수가 같으면 세트 비교
            {
                if(m.find(v[j])->second.second < m.find(v[j+1])->second.second)
                {
                    string tmp = v[j+1];
                    v[j+1] = v[j];
                    v[j] = tmp;
                }
                else if(m.find(v[j])->second.second == m.find(v[j+1])->second.second) //세트수도 같으면... 사전순 정렬
                {
                    if(v[j].compare(v[j+1])>0)
                    {
                        string tmp = v[j+1];
                    v[j+1] = v[j];
                    v[j] = tmp;
                    }
                }
            }
        }
    }

    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " " << m[v[i]].first << " " <<  m[v[i]].second << endl;
    }

    return 0;
}