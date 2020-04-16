#include <iostream>
#include <string.h>
#include <tuple>
#include <queue>
using namespace std;
int map[102][102];
vector<pair<int, int>> worm(5);//0,1,2,3,4 //5,6,7,8,9
vector<pair<int, int>> worm2(5);
int game(int, int, int, int);
int main()
{
    int Test;
    cin >> Test;
    for(int t=1; t<=Test; t++)
    {
        memset(map, 0, sizeof(map));
        for(int i=0; i<5; i++)
        {
            worm[i] = make_pair(-1, -1);
            worm2[i] = make_pair(-1, -1);
        }
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                cin >> map[i][j];
                if(map[i][j] >= 6)
                {
                    if(worm[map[i][j]-6].first == -1)
                        worm[map[i][j]-6] = make_pair(i, j);
                    else
                        worm2[map[i][j]-6] = make_pair(i, j);
                }
            }
               
        int ans = 0;
        int max = 0;
        for(int i=1; i<=n; i++) 
            for(int j=1; j<=n; j++)   
                if(map[i][j] == 0)
        // int i = 0;int j = 2;
                    for(int k=0; k<4; k++)
                    {
                        ans = game(i, j, k, n);
                        // cout << "i " << i <<" j " <<  j << " k " << k << " ans " << ans << endl;
                        if(ans > max)
                            max = ans;
                    }      
            
        
        cout << "#" << t << " " << max << endl;    
    }
}

int game(int i, int j, int k, int n)
{
    int score = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(i, j, k));
    int x, y, l;
    while(!q.empty())
    {
        tie(x, y, l) = q.front();
        q.pop();
        // cout << "x " << x << " y " << y << " l " << l << " score " << score << endl;
        if(l ==0)
        {
            while(1)
            {
                x += 1;
                if((x == i && y == j && score != 0) || map[x][y] == -1) // 처음 온 곳이거나 블랙홀 -> 종료.
                    return score;
                if(x == n+1)
                {
                    score *= 2;
                    score++;
                    return score;
                }
                if(map[x][y] == 0)
                    continue;
                else if(map[x][y] == 1)
                {
                    q.push(make_tuple(x, y, 2));
                    score++;
                    break;
                }
                else if(map[x][y] == 4)
                {
                    q.push(make_tuple(x, y, 3));
                    score++;
                    break;
                }
                else if(map[x][y] == 3 || map[x][y] == 5 || map[x][y] == 2)
                {
                    q.push(make_tuple(x ,y, 1));
                    score++;
                    break;
                }
                        if(map[x][y] >=6 && map[x][y] <=10) // 만약에 웜홀이라면
        {
            if(worm[map[x][y]-6].first == x && worm[map[x][y]-6].second == y)
                q.push(make_tuple(worm2[map[x][y]-6].first, worm2[map[x][y]-6].second, l));
            else
                q.push(make_tuple(worm[map[x][y]-6].first, worm[map[x][y]-6].second, l));
            
            break;
        }
                                
            }
        }
        if(l ==1)
        {
            while(1)
            {

                x -= 1;
                if((x == i && y == j && score != 0) || map[x][y] == -1) // 처음 온 곳이거나 블랙홀 -> 종료.
                return score;
                if(x == 0)
                {
                    score *= 2;
                    score++;
                    return score;
                }
                if(map[x][y] == 0)
                    continue;
                else if(map[x][y] == 2)
                {
                    q.push(make_tuple(x, y, 2));
                    score++;
                    break;
                }
                else if(map[x][y] == 3)
                {
                    q.push(make_tuple(x, y, 3));
                    score++;
                    break;
                }
                else if(map[x][y] == 1 || map[x][y] == 5 || map[x][y] == 4)
                {
                    q.push(make_tuple(x, y, 0));
                    score++;
                    break;
                }
                        if(map[x][y] >=6 && map[x][y] <=10) // 만약에 웜홀이라면
        {
            if(worm[map[x][y]-6].first == x && worm[map[x][y]-6].second == y)
                q.push(make_tuple(worm2[map[x][y]-6].first, worm2[map[x][y]-6].second, l));
            else
                q.push(make_tuple(worm[map[x][y]-6].first, worm[map[x][y]-6].second, l));
            
            break;
        }
            }
        }
        if(l ==2)
        {
            while(1)
            {
                y += 1;
                if((x == i && y == j && score != 0) || map[x][y] == -1) // 처음 온 곳이거나 블랙홀 -> 종료.
                    return score;
                if(y == n+1)
                {
                    score *= 2;
                    score++;
                    return score;
                }
                if(map[x][y] == 0)
                    continue;
                else if(map[x][y] == 3)
                {
                    q.push(make_tuple(x, y, 0));
                    score++;
                    break;
                }
                else if(map[x][y] == 4)
                {
                    q.push(make_tuple(x, y, 1));
                    score++;
                    break;
                }
                else if(map[x][y] == 1 || map[x][y] == 5 || map[x][y] == 2)
                {
                    q.push(make_tuple(x, y, 3));
                    score++;
                    break;
                }
        if(map[x][y] >=6 && map[x][y] <=10) // 만약에 웜홀이라면
        {
            // cout << "worm " << worm[map[x][y]-6].first << " " << worm[map[x][y]-6].second << endl;
            // cout << "worm2 " << worm2[map[x][y]-6].first << " " << worm2[map[x][y]-6].second << endl;
            // cout << " x " << x << " y " << y << endl;
            if(worm[map[x][y]-6].first == x && worm[map[x][y]-6].second == y)
            {
 q.push(make_tuple(worm2[map[x][y]-6].first, worm2[map[x][y]-6].second, l));
//  cout << "if " << worm2[map[x][y]-6].first << " " << worm2[map[x][y]-6].second << endl;
            }
               
            else
            {
q.push(make_tuple(worm[map[x][y]-6].first, worm[map[x][y]-6].second, l));
// cout << "else " << worm[map[x][y]-6].first << " " << worm[map[x][y]-6].second << endl;
            }
                
            
            break;
        }
            }
        }
        if(l ==3)
        {
            while(1)
            {
                y -= 1;
                if((x == i && y == j && score != 0) || map[x][y] == -1) // 처음 온 곳이거나 블랙홀 -> 종료.
                    return score;
                if(y == 0)
                {
                    score *= 2;
                    score++;
                    return score;
                }
                if(map[x][y] == 0)
                    continue;
                else if(map[x][y] == 1)
                {
                    q.push(make_tuple(x, y, 1));
                    score++;
                    break;
                }
                else if(map[x][y] == 2)
                {
                    q.push(make_tuple(x, y, 0));
                    score++;
                    break;
                }
                else if(map[x][y] == 3 || map[x][y] == 5 || map[x][y] == 4)
                {
                    q.push(make_tuple(x, y, 2));
                    score++;
                    break;
                }
        if(map[x][y] >=6 && map[x][y] <=10) // 만약에 웜홀이라면
        {
            if(worm[map[x][y]-6].first == x && worm[map[x][y]-6].second == y)
                q.push(make_tuple(worm2[map[x][y]-6].first, worm2[map[x][y]-6].second, l));
            else
                q.push(make_tuple(worm[map[x][y]-6].first, worm[map[x][y]-6].second, l));
            
            break;
        }
            }
        }
    }
}