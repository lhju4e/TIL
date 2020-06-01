#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer = {0};
    if(n == 1)
        return answer;
    else
    {
        for(int i=2; i<=n; i++)
        {
            int size = answer.size();
            answer.push_back(0);
            for(int j=size-1; j>=0; j--)
            {
                answer.push_back(!answer[j]);
            }
        }
    }
    return answer;
}

int main()
{
    int n = 3;
    vector<int> answer;
    answer = solution(n);    
    for(int i=0; i<answer.size(); i++)
        cout << answer[i]<< " ";
    return 0;
}