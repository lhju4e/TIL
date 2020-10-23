#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int dx[6] = {-2, -2, 0, 0, 2, 2};
    int dy[6] = {-1, 1, -2, +2, -1, 1};
    int chess[200][200] = {};
    int answer = -1;
    queue<pair<pair<int, int>, int>> q;
    int N, r1, c1, r2, c2;
    cin >> N >> r1 >> c1 >> r2 >> c2;
    q.push(make_pair(make_pair(r1, c1), 0));
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        // cout << "x " << x << " y " << y << endl;
        q.pop();
        for(int k=0; k<6; k++)
        {
            int ddx = x + dx[k];
            int ddy = y + dy[k];
            if(ddx >= 0 && ddy >= 0 && ddx < N && ddy < N )
            { // 범위체크
                if(chess[ddx][ddy] && (chess[ddx][ddy] > cnt + 1))
                {
                    chess[ddx][ddy] = cnt + 1;
                    q.push(make_pair(make_pair(ddx, ddy), cnt + 1));
                }
                else if(chess[ddx][ddy] == 0)
                {
                   chess[ddx][ddy] = cnt + 1;
                    q.push(make_pair(make_pair(ddx, ddy), cnt + 1));                    
                } 
            }
        }
    }
    answer = chess[r2][c2];
    if(answer == 0)
        answer = -1;
    
    
    cout << answer;
}