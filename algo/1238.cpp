#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 가중치, 노드
    bool check[1001];
    // int city[1001][1001] = {0};
    int go[1001];
    int back[1001];
    memset(check, true, sizeof(check)); // true가 기본값. 지나가면 false로
    memset(go, 101, sizeof(go));
    memset(back, 101, sizeof(back));
    // memset(city, -1, sizeof(city)); // -1은 길이 없는것
    int N, M, X;
    int i, j, t;
    cin >> N >> M >> X;
    vector<vector<int>> city(N+1, vector<int>(N+1, -1));
    for(int k=0; k<M; k++)
    {
        cin >> i >> j >> t;
        city[i][j] = t;
    }
//     for(int k=1; k<=N; k++)
// {        for(int m=1; m<=N; m++)
//             cout << city[k][m] << " ";
//         cout << endl;}
    pq.push(make_pair(0, X));
    go[X] = 0;
    while(!pq.empty()) // 갈때
    {
        int cost = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        // cout << "cost, idx : "  << cost << " " << idx << " " << endl;
        check[idx] = false;
        for(int i=1; i<=N; i++)
        {
            if(city[idx][i]!= -1 && check[i])
            {
                if(go[i] > cost + city[idx][i])
                {
                    go[i] = cost + city[idx][i];
                    pq.push(make_pair(go[i], i));
                }
            }
        }
    }
    // cout << "go ==================== " << endl;
    // for(int i=1; i<=N; i++)
    //     cout << go[i] << " ";
    

    memset(check, true, sizeof(check)); // true가 기본값. 지나가면 false로
    pq.push(make_pair(0, X));
    back[X] = 0;
    while(!pq.empty()) // 올때
    {
        int cost = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
                // cout << "cost, idx : "  << cost << " " << idx << " " << endl;

        check[idx] = false;
        for(int i=1; i<=N; i++)
        {
            if(city[i][idx]!= -1 && check[i])
            {
                if(back[i] > cost + city[i][idx])
                {
                    back[i] = cost + city[i][idx];
                    pq.push(make_pair(back[i], i));
                }
            }
        }
    }
    // cout << "back ==================== " << endl;
    // for(int i=1; i<=N; i++)
    //     cout << back[i] << " ";
    int answer = 0;
    for(int i=1; i<=N; i++)
    {
        int tmp = go[i] + back[i];
        if(answer < tmp)
            answer = tmp;
    }
    cout << answer;
    return 0;   
}