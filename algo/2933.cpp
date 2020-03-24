#include <iostream>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
void check(int, int);
char CAVE[101][101];
char CAVE2[101][101];
int num[101];
int r, c;

int main()
{
    cin >> r >> c;
    string s;
    for (int i = r; i > 0; i--)
    {
        cin >> s;
        for (int j = 1; j <= c; j++)
        {
            CAVE[i][j] = s[j - 1];
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    bool left = false;
    for (int i = 0; i < n; i++)
    {
        if (left) // 오른쪽에서 칠 때
        {
            for (int j = c; j > 0; j--)
            {
                if (CAVE[num[i]][j] == 'x')
                {
                    check(num[i], j);
                    left = false;
                    break;
                }
            }
        }
        else // 왼쪽에서 칠 때
        {
            for (int j = 1; j <= c; j++)
            {
                if (CAVE[num[i]][j] == 'x')
                {
                    // cout << "left " << num[i] << " " << j << endl;
                    check(num[i], j);
                    left = true;
                    break;
                }
            }
        } // check함수에서 이동시킨 미네랄을 반영해줌.
        for (int i = r; i > 0; i--)
            for (int j = 1; j <= c; j++)
                    if(CAVE2[i][j] == 'x')
                    CAVE[i][j] = 'x';

    }

            for (int i = r; i > 0; i--)
        {
            for (int j = 1; j <= c; j++)
                cout << CAVE[i][j] << " ";
            cout << endl;
        }

    return 0;
}

void check(int x, int y)
{
    memset(CAVE2, '.', sizeof(CAVE2));
    CAVE[x][y] = '.';
    // cout << "x " << x  << " y " << y << endl;
    bool been[101][101]; // bfs에서 기본적으로 간 곳 다시 안가도록 체크하는 배열.
    memset(been, 0, sizeof(been));
    been[x][y] = true;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        // cout << "==============="<<endl;
        int min = 200; // 해당 그룹의 제일 낮은 높이.
        int move = 100; // 몇 칸 움직일지
        vector<pair<int, int>> minpair; // 제일 낮은 높이 저장 벡터( 여러개일 경우때문에 벡터 )
        queue<pair<int, int>> q; //검사 큐
        queue<pair<int, int>> group; // 분리되는 미네랄 큐
        if (x + dx[i] >= 1 && x + dx[i] <= r && y + dy[i] >= 1 && y + dy[i] <= c && CAVE[x + dx[i]][y + dy[i]] == 'x' && !been[x + dx[i]][y + dy[i]])
        { //부숴지는 미네랄 기준으로 4방향 검사.
            q.push(make_pair(x + dx[i], y + dy[i]));
            group.push(make_pair(x + dx[i], y + dy[i]));
            been[x + dx[i]][y + dy[i]] = true;
        }
        while (!q.empty()) // 큐가 빌 때까지
        { //부숴지는 미네랄 기준 4방향 미네랄 그룹 검사
            int a = q.front().first;
            int b = q.front().second;
            // cout << "a " << a << " b " << b << endl;
            q.pop();
            if (min > a) // 해당 그룹의 제일 낮은 높이 알아냄.
            {
                min = a;
                if (!minpair.empty())
                    minpair.clear();
                minpair.push_back(make_pair(a, b)); // 제일 낮은 높이의 좌표 넣어줌.
            }
            else if (min == a) // 제일 낮은 높이가 여러개일 경우.
                minpair.push_back(make_pair(a, b));

            for (int i = 0; i < 4; i++)
            { //bfs로 돌면서 q와 group에 그룹 미네랄을 넣어줌.
                if (a + dx[i] >= 1 && a + dx[i] <= r && b + dy[i] >= 1 && b + dy[i] <= c && CAVE[a + dx[i]][b + dy[i]] == 'x' && !been[a + dx[i]][b + dy[i]])
                {
                    q.push(make_pair(a + dx[i], b + dy[i]));
                    group.push(make_pair(a + dx[i], b + dy[i]));
                    been[a + dx[i]][b + dy[i]] = true; // 간 곳 체크
                }
            }
        }
        
        if (min != 1 && min != 200) // ㅜ위에서 알아낸 최소 높이가 1이 아닐 경우
        {
            // cout << " min " << min << endl;
            for (int k = 0; k < minpair.size(); k++) // 제일 낮은 높이 좌표들을 돌면서 몇 칸을 움직일지 세줌.
            {
                int tmp = 0;
                int a1 = minpair[k].first;
                int a2 = minpair[k].second;
                // cout << "a1 " << a1 << " a2 " << a2 << endl;
                for (int l = a1 - 1; l >= 1; l--)
                {
                    if (CAVE[l][a2] == 'x')
                        break;
                    tmp++;
                }
                if (move > tmp) 
                    move = tmp;
            }
            // cout << "move " << move << endl;
            //위에서 q 큐는 다 비워졌으므로 group큐를 사용해서 해당 그룹의 미네랄들을 이동시킴.
            while (!group.empty())
            { // CAVE배열에서 CAVE2배열로 이동한 위치를 갱신시킴.
                int a1 = group.front().first;
                int a2 = group.front().second;
                // cout << "x " << a1 << " y " << a2 << endl;
                group.pop();
                CAVE[a1][a2] = '.'; 
                CAVE2[a1 - move][a2] = 'x';
                been[a1-move][a2]= true; // 간 곳 체크.
            }
        }
        else // 만약 최소 높이가 1이면 ( 이동시킬 필요가 없으면 ) group 큐 비워줌.
            while (!group.empty())
                group.pop();

    }
}