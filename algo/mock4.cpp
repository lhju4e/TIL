#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    map<long long, long long> m; // key : 객실. value : 찾아볼 객실 값.
        vector<long long> answer;

    for(int i=0; i<room_number.size(); i++)
    {
        if(m.find(room_number[i])== m.end())
        {
            answer.push_back(room_number[i]);
            m.insert(make_pair(room_number[i], room_number[i]+1));
        }
        else
        {
            for(int j=room_number[i]; j<=k;)
            {
                if(m.find(j) != m.end())
                {
                    j = m.find(j) -> second;
                }
                else
                {
                    m.insert(make_pair(j, j+1));
                    m[room_number[i]] = j+1;
                    answer.push_back(j);
                    break;
                }
            }
        }
    }
    return answer;
}

int main()
{
    vector<long long> answer;
    vector<long long> room_number = {1,3,4,1,3,1};
    answer = solution(10, room_number);
    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << " " ;
    return 0;
}