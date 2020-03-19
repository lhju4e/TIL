#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int index =0 ;
    priority_queue<int> pq;
    dates.push_back(k);
    while(index< dates.size())
    {
        // cout <<" index " << index;
        // cout << " stock " << stock << endl;
        if(stock >= dates[index])
        {
            pq.push(supplies[index]);
            index++;
        }
        else
        {
            // cout << " index " << index << endl;
            while(!pq.empty() && stock < dates[index])
            {
                stock += pq.top();
                pq.pop();
                answer++;
                if(stock>= k)
                    return answer;
            }
        }   
    }
    return answer;
}

int main()
{
    vector<int> d = {1, 10, 15};
    vector<int> sup = {20, 5, 10};

    cout << solution(1, d, sup, 31);
    return 0;
}