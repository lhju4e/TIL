#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
// 최댓값 삭제 -> 해당 값 0으로 만들고 최소값 삭제.
// 맨 뒤의 값 받아오기?
vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    deque<int> q;
    string s;
    for (int i = 0; i < operations.size(); i++)
    {
        s = operations[i];
        if (s[0] == 'I')
        {
            s = s.substr(2, s.size() - 2);
            q.push_front(atoi(s.c_str()));
            sort(q.begin(), q.end());

        }
        else if (s[0] == 'D')
        {
            if(!q.empty())
            if (s[2] == '1')
            {
                q.pop_back();

            }
            else
                q.pop_front();
            

        }
    }
    if(q.empty())
        answer = {0, 0};
    else
    {
                answer.push_back(q.back());

        answer.push_back(q.front());
    }

    
    return answer;
}

int main()
{
    vector<string> ans = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
    vector<int> an2;
    an2 = solution(ans);
    for (int i = 0; i < an2.size(); i++)
        cout << an2[i] << " ";
    return 0;
}