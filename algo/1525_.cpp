#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <cstring>
#include <tuple>
#include <algorithm>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
  int t = 0;
  scanf("%d", &t);
  for (int k = 0; k < t; k++)
  {
    int result = 0;
    char map[100][100];
    bool check[100][100];
    bool door[100][100];
    memset(door, false, sizeof(door));
    memset(check, false, sizeof(check));
    queue<pair<int, int>> q;
    vector<tuple<char, int, int>> door_xy;
    int h, w = 0;
    string key;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
        {
          cin >> map[i][j];
          if(j == 0 || j == w-1 |i ==0 || i==h-1)
            {
            if(map[i][j] != '*')
              {
                q.push(make_pair(i, j)); // 벽만 아니라면 일단 다 넣어줌
              check[i][j] = true;
              }
            }
        }
    }
    cin >> key;
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);
    // cout << key << endl;

    while (!q.empty())
    {
      //         for(int i=0; i<h; i++)
      // {for(int j=0; j<w; j++)
      //   if(check[i][j] == true)
      //     cout << '#';
      //   else
      //     cout << '\'';
      //   cout << endl;}
      //   cout << endl;

      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      if (map[x][y] == '$')
      {
        check[x][y] = true;
        result++;
      }
      else if (map[x][y] >= 'A' && map[x][y] <= 'Z') // 만약에 문을 만난다면
      {
        // cout << "door : " << door << endl;
        if (key.find(map[x][y]) == string::npos) // 열쇠 있는지 체크 - 없으면
          {
          door_xy.push_back(make_tuple(map[x][y], x, y)); //열쇠없으면 보류
          door[x][y] = false;
          continue;
          }
        else
          door[x][y] = true;      
      }
      else if (map[x][y] >= 'a' && map[x][y] <= 'z') // 열쇠를 만나면
      {
        check[x][y] = true;
        map[x][y] = map[x][y] - 32;
        key += map[x][y];
        // cout << "key : "<< key << endl;
        for (int iter = 0; iter < door_xy.size(); iter++)
        {
          if (map[x][y] == get<0>(door_xy[iter])) // 열쇠에 맞는 문이 있다면
          {
            int nx, ny = 0;
            char tmp;
            tie(tmp, nx, ny) = door_xy[iter];
            if(door[nx][ny] == false)
              q.push(make_pair(nx, ny)); // 갈 수 있게 넣어줌
          }
        }
      }
        for (int m = 0; m < 4; m++)
        {
          int sx = x + dx[m];
          int sy = y + dy[m];
          if (sx < h && sx >= 0 && sy < w && sy >= 0)
            if (check[sx][sy] == false && map[sx][sy] != '*') // 벽이 아니고 안갔으면
            {
              q.push(make_pair(sx, sy));
              check[x][y] = true;
            }
        }
    }
    cout << result << endl;
  }
  return 0;
}