#include <iostream>
// #include <string.h>
using namespace std;
int map[102][102];
int n, ans, MAX;
pair<int, int> worm[5]; //0,1,2,3,4 //5,6,7,8,9
pair<int, int> worm2[5];
int game(int, int, int);
int main()
{
    int Test;
    cin >> Test;
    for (int t = 1; t <= Test; t++)
    {
        // memset(map, 0, sizeof(map));
        for (int i = 0; i < 5; i++)
        {
            worm[i] = make_pair(0, 0);
            worm2[i] = make_pair(0, 0);
        }
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> map[i][j];
                if (map[i][j] >= 6)
                {
                    if (worm[map[i][j] - 6].first == 0)
                        worm[map[i][j] - 6] = make_pair(i, j);
                    else
                        worm2[map[i][j] - 6] = make_pair(i, j);
                }
            }

        ans = 0;
        MAX = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (map[i][j] == 0)
                    // int i = 1;int j = 4;
                    for (int k = 1; k < 5; k++)
                    {
                        ans = game(i, j, k);
                        // cout << "i " << i <<" j " <<  j << " k " << k << " ans " << ans << endl;
                        if (ans > MAX)
                            MAX = ans;
                    }
                    
        cout << "#" << t << " " << MAX << endl;
    }
}

int game(int i, int j, int k)
{
    //k - 방향. 1: 위. 2 : 오른쪽. 3 : 아래. 4 : 왼쪽.
    int score = 0;
    int x = i;
    int y = j;
    bool check = false; // 시작하자마자 나가지 않게 하기 위함.
    while (1)
    {
        // cout << "x " << x << " y " << y << " k " << k << " score " << score << endl;

        //1. 해당 칸 검사.
        if (map[x][y] == -1) // 블랙홀 -> 종료.
            return score;
        if(i==x && j==y && check)
            return score;
        if (x == n + 1 || x == 0 || y == 0 || y == n + 1)
        {
            score *= 2;
            score++;
            return score;
        }
        if (map[x][y] >= 6) // 만약에 웜홀이라면
        {
            if (worm[map[x][y] - 6].first == x && worm[map[x][y] - 6].second == y)
            {
                int dx = worm2[map[x][y] - 6].first;
                int dy = worm2[map[x][y] - 6].second;
                x = dx;
                y = dy;
            }
            else
            {
                int dx = worm[map[x][y] - 6].first;
                int dy = worm[map[x][y] - 6].second;
                x = dx;
                y = dy;
            }
        }
        else if (map[x][y] == 1)
        {
            if (k == 1 || k == 2)
            {
                score *= 2;
                score++;
                return score;
            }
            else if (k == 3)
                k = 2;
            else
                k = 1;
            score++;
        }
        else if (map[x][y] == 2)
        {
            if (k == 1)
                k = 2;
            else if (k == 2 || k == 3)
            {
                score *= 2;
                score++;
                return score;
            }
            else
                k = 3;
            score++;
        }
        else if (map[x][y] == 3)
        {
            if (k == 1)
                k = 4;
            else if (k == 2)
                k = 3;
            else if (k == 3 || k == 4)
            {
                score *= 2;
                score++;
                return score;
            }
            score++;
        }
        else if (map[x][y] == 4)
        {
            if (k == 1 || k == 4)
            {
                score *= 2;
                score++;
                return score;
            }
            else if (k == 2)
                k = 1;
            else if (k == 3)
                k = 4;
            score++;
        }
        else if (map[x][y] == 5)
        {
            score *= 2;
            score++;
            return score;
        }
        //2. 방향검사 후 이동.
        if (k == 1)
            x -= 1;
        else if (k == 2)
            y += 1;
        else if (k == 3)
            x += 1;
        else
            y -= 1;

        check = true;
    }
}