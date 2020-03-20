#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> job; // 작업시간, 들어온 시간.
    for(int i=0; i<jobs.size(); i++)
        job.push(make_pair(jobs[i][0], jobs[i][1]));
    for(int i=0; i<jobs.size(); i++)
    {
        jobs[i][0] = job.top().first;
        jobs[i][1] = job.top().second;
        job.pop();
    }
    //작업하는데 걸리는 시간, 들어온 시간
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 작업시간, 들어온 시간.
    int time = 0;
    int index = 0;
    while (index < jobs.size())
    {
        cout << "index " << index << endl;
        while (pq.empty() && index < jobs.size())
        {
            if (jobs[index][0] <= time)
            {
                pq.push(make_pair(jobs[index][1], jobs[index][0]));
                index++;
            }
            else
                time++;
        }
        while (!pq.empty())
        {
            // cout << "pq top " << pq.top().first << endl;
            answer += (time - pq.top().second) + pq.top().first;
            // cout << "answer " << answer << endl;
            time += pq.top().first;
            pq.pop();

            while(index < jobs.size())
            {
                if(jobs[index][0] <= time)
                {
                    pq.push(make_pair(jobs[index][1], jobs[index][0]));
                    index++;
                }
                else
                    break;
            }
        }
    }

    return answer / jobs.size();
}

int main()
{
    vector<vector<int>> jobs = {{0,3}, {4,1}, {5,3},{5,2},{7,1}};
    cout << solution(jobs) << endl;
    return 0;
}