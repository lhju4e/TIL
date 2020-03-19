#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    answer.push_back(0);
    int k = 0;
    int prev = 0;
    for(int i=0; i<progresses.size(); i++)
    {
        int remain = 100 - progresses[i];
        if(remain % speeds[i])
            remain = remain/speeds[i] + 1;
        else
            remain = remain / speeds[i]; // i번째 작업에 필요한 날짜.
        if(i == 0)
            prev = remain;
        // cout << "remain " << remain << endl;
        if(remain<= prev) // 앞에 날짜보다 더 빠르거나 같게 완성되었다면
            answer[k]++;
        else // 앞에 날짜보다 느리게 완성되었다면
        {
            // cout << "k " << k  << "remain " << remain << endl;
            answer.push_back(1);
            prev = remain;
            k++;
        }
    }
    return answer;
}

int main()
{
    vector<int> pro = {93, 30, 55};
    vector<int> speed = {1, 30, 5};
    vector<int> ans;
    ans = solution(pro, speed);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}