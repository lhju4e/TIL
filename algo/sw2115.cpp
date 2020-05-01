#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int MAP[10][10];
vector<pair<pair<int, int>, pair<int, int>>> v; // 꿀, 몇 칸인지, 좌표
bool chk[10][10];
int main()
{
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        v.clear();
        int n, m, c;
        cin >> n >> m >> c;
        int check = true;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> MAP[i][j];
        for (int k = 1; k <= m; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int honey = 0;
                    check = true;
                    for (int l = 0; l < k; l++)
                    {
                        int y = j + l;
                        // cout << "i " << i << " y " << y << endl;
                        if (y >= n)
                        {
                            check = false;
                            break;
                        }
                        honey += MAP[i][y];
                        if (honey > c)
                        {
                            check = false;
                            break;
                        }
                    }
                    if (check)
                    {
                        v.push_back(make_pair(make_pair(honey, k), make_pair(i, j)));
                    }
                }
            }
        }

        sort(v.begin(), v.end());

        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << "honey " << v[i].first.first << " k " << v[i].first.second << " i "  << v[i].second.first << " j " << v[i].second.second << endl;
        // }

        int MAX = 0;
        //중복체크
        for (int q = v.size() - 1; q > 0; q--)
        {
            int idx = 0;
            int ans = 0;
            int ans2 = 0;
            memset(chk, false, sizeof(chk));
            for(int i=0; i<m; i++)
                chk[v[q].second.first][v[q].second.second+i] = true;
            for (int i = 0; i < v[q].first.second; i++)
            {  
                cout << " first x, y => x " << v[q].second.first << " y " << v[q].second.second + i << endl;
                ans += MAP[v[q].second.first][v[q].second.second + i] * MAP[v[q].second.first][v[q].second.second + i];
            }
            for (int i = q - 1; i >= 0; i--)
            {
                ans2 = 0;
                check = true;
                for (int k = 0; k < v[i].first.second; k++)
                {
                    if (chk[v[i].second.first][v[i].second.second+k]) // 겹친다면
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    for (int j = 0; j < v[i].first.second; j++)
                    {
                        ans2 += MAP[v[i].second.first][v[i].second.second + j] * MAP[v[i].second.first][v[i].second.second + j];
                        cout << " second x, y => x " << v[i].second.first << " y " << v[i].second.second + j << endl;
                    }
                    cout << "===ans  " << ans + ans2 << endl;
                    if (ans+ans2 > MAX)
                        MAX = ans + ans2;
                }
            }
        }

        cout << "#" << t << " " << MAX << endl;
    }
}