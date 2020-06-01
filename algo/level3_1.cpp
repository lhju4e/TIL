#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long cnt = 0;
void dfs(int x, int y, int m, int n, vector<vector<int>>);

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dfs(1, 1, m, n, puddles);
    cnt = cnt % 1000000007;
    answer = cnt;
    return answer;
}

int main()
{
    int m = 5;
    int n = 4;
    vector<vector<int>> puddles = {{3, 2}, {2,3}};
    cout << solution(m, n, puddles);
    return 0;
}

void dfs(int x, int y, int m, int n, vector<vector<int>> puddles)
{
    if(x >m || y > n)
        return;
    for(int i=0; i<puddles.size(); i++)
    {
        if(x == puddles[i][0] && y == puddles[i][1])
            return;
    }
    if(x == m && y == n)
    {
        cnt++;
        return;
    }
    else
    {
        dfs(x+1, y, m, n, puddles);
        dfs(x, y+1, m, n, puddles);
    }
}