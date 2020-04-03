#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    int pre, next;
    bool check = true;
    for (int i = 0; i < skill_trees.size(); i++)
    {
        check = true;
        pre = skill_trees[i].find(skill.at(0));
        for (int j = 1; j < skill.size(); j++)
        {
            next = skill_trees[i].find(skill.at(j));
            if(pre == -1) // skill에서 못찾으면 평생 못배우는걸로.
                pre = 30;
            if(next == -1)
                next = 30;
            // cout << skill_trees[i] << endl;
            // cout << "pre " << pre << " next " << next << endl;
            if (pre > next)
            {
                check = false;
                break;
            }
            pre = next;
        }
        if (check)
            answer++;
    }
    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    cout << solution(skill, skill_trees);
    return 0;
}