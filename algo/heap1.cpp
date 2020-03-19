#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int count = 0; // 코스빌 지수를 넘기는 갯수
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0; i<scoville.size(); i++)
    {
        q.push(scoville[i]);
        if(scoville[i] >= K)
            count++;
    }
    while(q.size() > count)
    {
        // cout << "=============="<<endl;
        if(q.size() == 1)
            return -1;
        int first = q.top();
                q.pop();
        int second = q.top();
        // cout << first << " " << second << endl;
 q.pop();
        answer++;

        int nw = first + (second * 2);
        q.push(nw);
        if(nw>=K)
            count++;
        // cout << "nw " << nw << endl;
        // cout << "count " << count << " size " << q.size() << endl;
    }

    return answer;
}

int main()
{
    vector<int> s = {1, 2,3, 9, 10, 12};
    cout << solution(s, 10);
    return 0;
}