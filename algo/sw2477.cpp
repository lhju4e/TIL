#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int A[10]; // 0번 인덱스는 사용하지 않겠음. 1번~9번
int B[10];
int a_time[10];
int b_time[10];
vector<pair<int, bool>> people;
queue<int> come;
queue<int> wait;
vector<int> ans_v;
int main()
{
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        while (!come.empty())
            come.pop();
        while (!wait.empty())
            wait.pop();
        people.clear();
        ans_v.clear();
        int n, m, k, w1, w2, tmp;
        cin >> n >> m >> k >> w1 >> w2;
        for (int i = 1; i <= n; i++)
        {
            A[i] = -1;
            cin >> a_time[i];
        }

        for (int i = 1; i <= m; i++)
        {
            B[i] = -1;
            cin >> b_time[i];
        }

        for (int i = 0; i < k; i++)
        {
            cin >> tmp;
            wait.push(i); // 큐에는 사람들 인덱스로 넣음.
            people.push_back(make_pair(tmp, false));
        }
        int time = 0;
        time = people[0].first;
        bool check = true;
        bool finish = false;
        while (!finish)
        {
            finish = true;
            //time에 맞춰서 접수창구에서 빼서 come큐로 옮겨야함.
            for (int i = 1; i <= n; i++)
            {
                if (A[i] != -1)
                {
                    finish = false;
                    if (time >= people[A[i]].first)
                    {
                        come.push(A[i]);
                        A[i] = -1;
                    }
                }
            }
            check = true;
            while (!wait.empty() && check)
            {
                finish = false;
                check = false;
                if (time >= people[wait.front()].first)
                {
                    for (int i = 1; i <= n; i++)
                    {
                        if (A[i] == -1) // 접수 창구가 비어있다면
                        {
                            check = true;
                            A[i] = wait.front(); //여기도 인덱스로 넣어줌.
                            wait.pop();
                            people[A[i]].first = time + a_time[i];
                            if (i == w1)
                                people[A[i]].second = true;
                            break;
                        }
                    }
                }
                else
                    break;
            }
            for (int i = 1; i <= m; i++)
            {
                if (B[i] != -1)
                {
                    finish = false;
                    if (time >= people[B[i]].first)
                        B[i] = -1;
                }
            }

            for (int i = 1; i <= m; i++)
            {
                if (!come.empty())
                {
                    finish = false;
                    if (B[i] == -1)
                    {
                        B[i] = come.front();
                        come.pop();
                        people[B[i]].first = time + b_time[i];
                        if (i == w2 && people[B[i]].second)
                            ans_v.push_back(B[i] + 1); // 정답.
                    }
                }
            }
            // std::cout << endl;
            // std::cout << "========time : " << time << endl;
            // cout << "wait q " << wait.front() << endl;
            // for (int i = 1; i <= n; i++)
            //     std::cout << A[i] << " ";
            // std::cout << endl;
            // cout << "come  q " << come.front() << endl;
            // for (int j = 1; j <= m; j++)
            //     std::cout << B[j] << " ";

            time++;
        }
        int ans = 0;
        for (int i = 0; i < ans_v.size(); i++)
            ans += ans_v[i];
        if(ans == 0)
            ans = -1;
        std::cout << "#" << t << " " << ans << endl;
    }
    return 0;
}