#include <iostream>
#include <vector>
using namespace std;
vector<pair<pair<int, int>, pair<int, int>>> v;
int MAP[4002][4002];
int main()
{
    int test;
    cin >> test;
    for(int t=1; t<=test; t++)
    {
        v.clear();
        int energy = 0;
        int atom;
        int x, y;
        int dir, k;
        cin >> atom;
        for(int i=0; i<atom; i++)
        {
            cin >> x >> y >> dir >> k;
            x = (x + 1000) * 2;
            y = (y + 1000) * 2;
            v.push_back(make_pair(make_pair(x, y), make_pair(dir, k)));
        }
        for(int time = 0; time<=4000; time++)
        {
            // cout << "====time " << time << " ene " << energy << endl;
            // for(int i=0; i<v.size(); i++)
            // {
            //     cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.second << endl;
            // }
            for(int i=0; i<v.size(); i++)
            {
                if(v[i].second.second == -1)
                    continue;
                                    MAP[v[i].first.first][v[i].first.second] = 0;

                // x = v[i].first.first;
                // y = v[i].first.second;
                dir = v[i].second.first;
                if(dir == 0 )
                    v[i].first.second += 1;
                else if(dir == 1)
                    v[i].first.second -= 1;
                else if(dir == 2)
                    v[i].first.first -= 1;
                else if(dir == 3)
                    v[i].first.first += 1;

                x = v[i].first.first;
                y = v[i].first.second;
                if(x<0 || y<0 || x>=4002 || y>=4002)
                {
                    v[i].second.second = -1;
                    continue;
                }
                if(MAP[x][y])
                {
                    energy += v[i].second.second;
                    v[i].second.second = -1;
                    if(v[MAP[x][y]-1].second.second != -1)
                    {
                        energy += v[MAP[x][y]-1].second.second;
                        v[MAP[x][y]-1].second.second = -1;
                    }
                }
                else
                    MAP[x][y] = i+1;
                }
            
            // for(int i=0; i<v.size(); i++)
            // {
            //     if(v[i].second.second == -1)
            //         continue;
            //     bool check = false;
            //     x = v[i].first.first;
            //     y = v[i].first.second;
            //     for(int j=i+1; j<v.size(); j++)
            //     {
            //         double dx = v[j].first.first;
            //         double dy = v[j].first.second;
            //         if(x == dx && y == dy)
            //         {
            //             check = true;
            //             energy += v[j].second.second;
            //             v[j].second.second = -1;
            //         }
            //     }
            //     if(check)
            //     {
            //         energy += v[i].second.second;
            //         v[i].second.second = -1;
            //     }
            // }
            
        }

        cout << "#" << t << " " << energy << endl;
    }
    return 0;
}