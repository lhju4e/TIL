#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0; i<skill_trees.size(); i++)
    {
        int idx = 0;
        int pre = 0;
        bool check = true;
        for(int j=0; j<skill.size(); j++)
        {
            pre = idx;
            idx = skill_trees[i].find(skill.at(j));
            if(idx == string::npos )
            {
                idx = skill_trees.size();
            }
            if(pre > idx)
            {
                check =false;
                break;
            }
        }
        if(check)
            answer++;
    }
    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> skill_trees= {"BACDE", "CBADF", "AECB", "BDA"};
    cout << solution(skill, skill_trees);
    return 0;
}