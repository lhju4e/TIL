#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int MAP[100][100];
int check[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<pair<int, int>, pair<int, int>>> v;
int main()
{
    int test;
    cin >> test;
    for(int t=1; t<=test; t++)
    {
        v.clear();
        memset(check, 0, sizeof(check));
        memset(MAP, 0, sizeof(MAP));
        int n, m, k;
        int x, y, num, dir;
        cin >> n >> m >> k;
        for(int i=0; i<k; i++)
        {
            cin >> x >> y >> num >> dir; 
            v.push_back(make_pair(make_pair(x, y), make_pair(num, dir)));
        }

        while(m>0)
        {
            // cout << endl;
            memset(check, 0, sizeof(check));
            m--;
            for(int i=0; i<k; i++) // 1. 군집 이동
            {
                x = v[i].first.first;
                y = v[i].first.second;
                num = v[i].second.first;
                dir = v[i].second.second;
                // cout << "x " << x << " y " << y << " num " << num  << " dir " << dir << endl;
                if(num == 0)
                    continue;
                x = x + dx[dir-1]; // dir : 1, 2,3, 4. 배열은 -1씩
                y = y + dy[dir-1];
                check[x][y]++;
                if(x == 0 || y == 0 || x == n-1 || y == n-1)
                {
                    if(dir ==1 || dir == 3)
                        dir += 1;
                    else if(dir == 2 || dir == 4)
                        dir -= 1;
                    num = num / 2;
                }
                v[i] = make_pair(make_pair(x, y), make_pair(num, dir));
            }
            for(int i=0; i<n; i++) // 군집 합체
            {
                for(int j=0; j<n; j++)
                {
                    if(check[i][j]>1)
                    {
                        pair<int, int> p; // 가장 큰 게 몇 번째 클러스터인지, 방향
                        int max = 0;
                        int nums = 0;
                        for(int q=0; q<k; q++)
                        {
                            if(v[q].first.first == i && v[q].first.second == j)
                            {
                                nums += v[q].second.first;
                                if(max < v[q].second.first)
                                {
                                    p = make_pair(q, v[q].second.second);
                                    max = v[q].second.first;
                                }
                                v[q].second.first = 0; // num = 0로 만듦.     
                            }
                        }
                        int q = p.first;
                        dir = p.second;
                        v[q] = make_pair(make_pair(i, j), make_pair(nums,dir));
                    }
                }
            }

        }
        int cnt = 0;
         for(int i=0; i<k; i++) 
        {
            cnt += v[i].second.first;
        }
        cout << "#" << t << " " << cnt << endl;
    }
}