#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int current_weight = truck_weights[0];
    queue<int> truck;
    for(int i=1; i<truck_weights.size(); i++)
        truck.push(truck_weights[i]);
    queue<pair<int, int>> q; // 무게, 시간
    q.push(make_pair(truck_weights[0], 1));
    while(!q.empty())
    {
        answer++;
    
        // cout << answer << endl;
        while(!q.empty())
        {
            int tmp = q.front().second;
            if(answer >= tmp + bridge_length)
                {
                    current_weight -= q.front().first;
                    // cout << answer << " " << q.front().first<<endl;
                    q.pop();}
            else
                break;      
        }
        if(!truck.empty())
        {
            current_weight += truck.front();
            if(weight >= current_weight)
            {
                q.push(make_pair(truck.front(), answer));
                truck.pop();
            }
            else
                current_weight -= truck.front();
        } 
    }
    return answer;
}

int main()
{
    vector<int> truck = {10,10,10,10,10,10,10,10,10,10};
    cout << solution(100, 100, truck);
}