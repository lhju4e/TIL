#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int bfs(int, int, int[][50]);
bool check[50][50] = {false};

int main()
{
  int w, h;
  cin >> h >> w;
  //cout << "w h " << w << h << endl;
  int a[50][50] = {0};

  while (w != 0 || h != 0)
  {
    for (int i = 0; i < w; i++)
      for (int j = 0; j < h; j++)
        cin >> a[i][j];
    // for (int i = 0; i < w; i++)
    //   {
    //     {for (int j = 0; j < h; j++)
    //       cout << a[i][j];}
    //     cout << endl;
    //     }
    int result = bfs(w, h, a);
    cout << result << endl;
    cin >> h >> w;
    memset(a, 0, sizeof(a));
  }
  return 0;
}

int bfs(int w, int h, int a[][50])
{
  queue<pair<int, int>> q;
  int count = 0;
  int x, y = 0;
  int dx, dy = 0;
  int x_shift[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
  int y_shift[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
  memset(check, false, sizeof(check));
  for (int i = 0; i < w; i++)
    for (int j = 0; j < h; j++)
    {
      if (check[i][j] == false && a[i][j] == 1)
      {
  //      cout << " count i j " << i <<" "<< j << endl;
        q.push(make_pair(i, j));
        check[i][j] = true;
        count++;
        while (!q.empty())
        {
          x = q.front().first;
          y = q.front().second;
         // cout << "q front " << x << " " << y << endl;
          q.pop();

            for (int k=0; k<9; k++)
            {
              dx = x + x_shift[k];
              dy = y + y_shift[k];
              if(dx < 0 || dx >= w)
                continue;
              else if(dy < 0 || dy >= h)
                continue;
              else if (check[dx][dy] == false && a[dx][dy] == 1)
                {q.push(make_pair(dx, dy));
         //         cout <<"check x y " << x+dir[k]  << y+dir[l]<<endl;
                }
              check[dx][dy] = true;
            }
        }
      }
    }
  return count;
}