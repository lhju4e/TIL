#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems)
{
    map<string, int> jewel;
    vector<int> answer;

    for (int i = 0; i < gems.size(); i++)
        jewel.insert(make_pair(gems[i], 0));
    
    map<string, int> copy;
    int kind = jewel.size();
            map<string, int> buy;
        int idx1 = 0;
        int idx2 = kind - 1;
        for (int i = idx1; i <= idx2; i++)
            buy[gems[i]]++;

        if (buy.size() == kind)
        {
            answer.push_back(idx1+1);
            answer.push_back(idx2+1);
            return answer;
        }

        idx2++;
        
        for (; idx2 < gems.size(); idx2++)
        {
            buy[gems[idx2]]++;
            if (buy.size() == kind)
                break;
        }
        for(;idx1< gems.size(); idx1++)
        {
            // cout << "idx1 " << idx1 << " idx2 " << idx2 << endl;
            buy[gems[idx1]]--;
            if (buy.find(gems[idx1])->second == 0)
                buy.erase(gems[idx1]);
            if(buy.size() != kind)
                break;
        }
        answer.push_back(idx1+1);
        answer.push_back(idx2+1);

    return answer;
}

int main()
{
    vector<int> ans;
    // vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<string> gems = {"AA", "AB", "AC", "AA", "AC"};
    // vector<string> gems = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};

    ans = solution(gems);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}