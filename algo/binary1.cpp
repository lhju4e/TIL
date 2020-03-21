#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int need = 0;
    bool check = false;
    int over = 0;
    sort(budgets.begin(), budgets.end());
    for(int i=0; i<budgets.size(); i++)
        need += budgets[i];
    for(int i=0; i<budgets.size(); i++)
    {
        if(budgets[i] > M/4)
        {
            check = true;
            break;
        }
    }
    if(!check)
        return M/4;
    over = need - M;
    if(over <= 0)
        return budgets[budgets.size()-1];
        int index = 1;
    while(over > 0)
    {

    int tmp = (budgets[budgets.size()- index] - budgets[budgets.size()-index - 1])*index;
            // cout << " over " << over << " tmp " << tmp << endl;
    if(tmp >= over)
    {
        int a = over/index;
        if(over%index)
            a+=1;
        return budgets[budgets.size()-index] - a;
    }
        
    else
    {
        budgets[budgets.size()-index] -= tmp;
        answer = budgets[budgets.size()-index];
        over -= tmp;
        // cout << " tmp " << tmp;
        // cout << " over " << over << " answer " << answer << endl;
    }
    index++;
    }
    return answer;
}

int main()
{
    vector<int> b = {120, 110, 140, 150};
    cout << solution(b, 485);
    return 0;
}