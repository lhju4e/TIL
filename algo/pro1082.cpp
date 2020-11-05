#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    map<string, int> m;
    string s_tmp = s.substr(1, s.length()-2);
    int right = s_tmp.find("}");
    int left = s_tmp.find("{");
    while(right != string::npos)
    {
        string s_tmp2 = s_tmp.substr(left+1, right-left-1);
        int index = s_tmp2.find(",");
        int index2 = 0;
        while(index != string::npos)
        {
            m[s_tmp2.substr(index2, index - index2)]++;
            index2 = index+1;
            index = s_tmp2.find(",", index2);           
        }
        m[s_tmp2.substr(index2)]++;
        if(right+1 < s_tmp.length())
        {
            right = s_tmp.find("}", right+1);
            left = s_tmp.find("{", left+1);       
        }
        else
            break;
    }
    vector<pair<int, int>> v;
    for(map<string, int>::iterator iter = m.begin(); iter!=m.end(); iter++)
        v.push_back(make_pair(iter->second, stoi(iter->first)));
    
    sort(v.begin(), v.end());
    vector<int> answer;
    for(int i=v.size()-1; i>=0; i--)
        answer.push_back(v[i].second);
    return answer;
}

int main()
{
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    vector<int> answer = solution(s);
    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << " ";
    return 0;
}