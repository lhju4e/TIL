#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool check[200][200];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<pair<int, int>> q;
    memset(check, false, sizeof(check));
    for(int i=0; i<n; i++)
    {
        if(!check[i][i])
        {
            q.push(make_pair(i, i));
            check[i][i] = true;
            answer++;
        }
        // cout << answer << endl;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0; k<n; k++)
            {
                if(!check[y][k] && computers[y][k])
                {
                    q.push(make_pair(y, k));
                    check[y][k] = true;
                }     
            }
        }
        
    }

    return answer;
}

int main()
{
    int n = 4;
    vector<vector<int>> computers = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0},{1, 1, 0, 1}};
    cout << solution(n, computers);
    return 0;
}