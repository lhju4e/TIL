#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int MAP[10][10];
pair<int, int> ps1; // 계단좌표
pair<int, int> ps2;
vector<pair<int, int>> people;
priority_queue<int, vector<int>, greater<int> > v1;
priority_queue<int, vector<int>, greater<int> > v2;
int main()
{
    int test;
    int n;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        ps1 = make_pair(-1, -1);
        ps2 = make_pair(-1, -1);
        people.clear();
        memset(MAP, 0, sizeof(MAP));

        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> MAP[i][j];
                if (MAP[i][j] == 1)
                    people.push_back(make_pair(i, j));
                if (MAP[i][j] >= 2)
                    if (ps1.first == -1)
                        ps1 = make_pair(i, j);
                    else
                        ps2 = make_pair(i, j);
            }

        int MIN = 100;
        //i : 첫번째 계단으로 갈 사람들 , j : 두번쨰 계단으로 갈 사람들 (명수).
        //몇명이 어떤 계단으로 갈지 구하고, 조합으로 쭉 돌림.

        for (int i = 0; i <= people.size(); i++)
        {
            vector<int> tmp;
            for (int j = 0; j < i; j++)
                tmp.push_back(0);
            for (int j = i; j < people.size(); j++)
                tmp.push_back(1);

            //cout << endl;
            do
            {
                //v1은 1번 계단으로 가는 사람들 대기열. v2는 2번 계단.
                //stair는 계단을 내려가고 있는 사람들 (최대 3명, 그 이상은 못내려가고 대기해야됨.)

                // for (int k = 0; k < tmp.size(); k++)
                //     cout << tmp[k] << " ";
                int ans = 0;
                while (!v1.empty())
                    v1.pop();
                while (!v2.empty())
                    v2.pop();

                for (int j = 0; j < tmp.size(); j++)
                {
                    if (tmp[j] == 0)
                    {
                        int x = abs(people[j].first - ps1.first);
                        int y = abs(people[j].second - ps1.second);
                        v1.push(x + y); // 각 계단까지 도달하는 데에 걸리는 시간.
                    }
                    else
                    {
                        int x = abs(people[j].first - ps2.first);
                        int y = abs(people[j].second - ps2.second);
                        v2.push(x + y);
                    }
                }
                //계단 들어옴.
                int time = 0;
                queue<int> stair1;
                queue<int> stair2;
                //제일 빨리 도착하는 사람부터 시작해서 시간을 잼.
                if (v1.empty() || v1.top() > v2.top())
                {
                    time = v2.top();
                    while (!v2.empty() && time == v2.top())
                    {
                        stair2.push(v2.top()+1);
                        v2.pop();
                    }
                }
                else if (v2.empty() || v1.top() < v2.top())
                {
                    time = v1.top();
                    while (!v1.empty() && time == v1.top())
                    {
                        stair1.push(v1.top()+1);
                        v1.pop();
                    }

                }
                else if (v1.top() == v2.top())
                {
                    time = v1.top();
                    while (!v1.empty() && time == v1.top())
                    {
                        stair1.push(v1.top()+1);      
                        v1.pop();
                    }
                    while (!v2.empty() && time == v2.top())
                    {
                        stair2.push(v2.top() + 1);
                        v2.pop();
                    }

                }

                //대기, 가고 있는 계단 큐가 다 빌때까지 반복.
                while (!stair1.empty() || !stair2.empty() || !v1.empty() || !v2.empty())
                {
                    // cout << "v2.size() : " << v2.size() << endl;
                    // cout << !stair1.empty() << !stair2.empty() << !v1.empty() << !v2.empty() << endl;
                    time++;
                    // cout << "time " << time << endl;


                    while (!stair1.empty() && time >= stair1.front() + MAP[ps1.first][ps1.second])
                        stair1.pop();
                    // cout << "check 1 " << endl;

                    while (!stair2.empty() && time >= stair2.front() + MAP[ps2.first][ps2.second])
                        stair2.pop();
                    // cout << "check 2 " << endl;

                        while (!v1.empty() && v1.top() + 1<= time && stair1.size() < 3)
                        {
                            stair1.push(time);
                            v1.pop();
                        }
                    //    cout << "check 3 " << endl;

                        while (!v2.empty() && v2.top() + 1 <= time && stair2.size() < 3)
                        {
                            stair2.push(time);
                            v2.pop();
                        }
                    //    cout << "check 4 " << endl;

                    
                }
                ans = time;
                if (MIN > ans)
                    MIN = ans;
            } while (next_permutation(tmp.begin(), tmp.end()));
        }


        cout << "#" << t << " " << MIN << endl;
    }
}