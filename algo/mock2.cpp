#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool check[100001];
int order [501];
vector<int> solution(string s) {
    vector<vector <int>> sv;
    int k = 0;
    int index = 1;
    while(index < s.size() -1)
    {
        vector<int> tmp;
        int start = s.find("{", index);
        int end = s.find("}", index);
        string sub = s.substr(start + 1, end - start - 1);
        int subindex = 0;
        // cout << "sub " << sub << endl;
        while (1)
        {
            int end = sub.find(",", subindex);
            if (end != -1)
                tmp.push_back(stoi(sub.substr(subindex, end)));
            else
            {
                tmp.push_back(stoi(sub.substr(subindex)));
                break;
            }
            subindex = end + 1;
        }
        index = end + 1;
        order[tmp.size()] = sv.size();
        // for(int t=0; t<tmp.size(); t++)
        //     cout << tmp[t] << " " ;
        // cout << "sv.size : " << sv.size() << endl;
        // cout << endl;
        sv.push_back(tmp);
    }
    vector<int> answer;
    for(int i=1; i<=sv.size(); i++) // 여기서 i는 인덱스가 아니라 숫자의 갯수
    { // 1개 있는 배열먼저 돌고 2개 있는 배열, 3개 있는 배열 ... 
        for(int j=0; j<sv[order[i]].size(); j++)
        {
            if(!check[sv[order[i]][j]])
            {
                answer.push_back(sv[order[i]][j]);
                check[sv[order[i]][j]] = true;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
    vector<int> answer;
    answer =  solution(s);
    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << " " ;
}