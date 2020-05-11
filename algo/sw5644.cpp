#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> move_a;
vector<int> move_b;
vector<pair<pair<int, int>, pair<int, int>>> ap;
bool map[11][11][8];
int my[5] = {0, 0, 1, 0, -1};
int mx[5] = {0, -1, 0, 1, 0};
int main()
{
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        int charge_a = 0;
        int charge_b = 0;
        memset(map, false, sizeof(map));
        ap.clear();
        move_a.clear();
        move_b.clear();
        int M, A;
        cin >> M >> A;

        int a, b, c, d;
        for (int i = 0; i < M; i++)
        {
            cin >> a;
            move_a.push_back(a);
        }
        for (int i = 0; i < M; i++)
        {
            cin >> a;
            move_b.push_back(a);
        }
        for (int i = 0; i < A; i++)
        {
            cin >> a >> b >> c >> d;
            ap.push_back(make_pair(make_pair(b, a), make_pair(c, d)));
        }
        for (int i = 0; i < A; i++)
        {
            int x = ap[i].first.first;
            int y = ap[i].first.second;
            for (int k = 0; k <= ap[i].second.first; k++)
            {
                if (y + k <= 10)
                    map[x][y + k][i] = true;
                if (y - k >= 0)
                    map[x][y - k][i] = true;
            }
            int x1 = x - 1;
            int x2 = x + 1;
            for (c = ap[i].second.first - 1; c >= 0; c--)
            {
                for (int k = 0; k <= c; k++)
                {
                    if (x1 >= 0)
                    {
                        if (y + k <= 10)
                            map[x1][y + k][i] = true;
                        if (y - k >= 0)
                            map[x1][y - k][i] = true;
                    }
                    if (x2 <= 10)
                    {
                        if (y + k <= 10)
                            map[x2][y + k][i] = true;
                        if (y - k >= 0)
                            map[x2][y - k][i] = true;
                    }
                }
                x1--;
                x2++;
            }
        }
        // for(int i=1; i<=10; i++)
        // {
        //     for(int j=1; j<=10; j++)
        //         cout << map[i][j][0] << " ";
        //     cout << endl;
        // }
        // cout << endl;
        // for(int i=1; i<=10; i++)
        // {
        //     for(int j=1; j<=10; j++)
        //         cout << map[i][j][1] << " ";
        //     cout << endl;
        // }
        // cout << endl;
 
        int ax = 1;
        int ay = 1;
        int bx = 10;
        int by = 10;
        pair<int, int> a1; // 인덱스, 값
        pair<int, int> a2;
        pair<int, int> b1;
        pair<int, int> b2;
        for (int i = 0; i <= M; i++)
        {
            a1 = make_pair(-1, 0);
            a2 = make_pair(-1, 0);
            b1 = make_pair(-1, 0);
            b2 = make_pair(-1, 0);
            // cout << "m: " << i <<endl;
            // cout << "a : " << ax << " " << ay << " b : " << bx << " " << by << endl;

            for (int k = 0; k < ap.size(); k++)
            {
                if (map[ax][ay][k])
                {
                    if (ap[k].second.second > a1.second)
                    {
                        a2.second = a1.second;
                        a2.first = a1.first;
                        a1.second = ap[k].second.second;
                        a1.first = k;
                    }
                    else if(ap[k].second.second > a2.second)
                    {
                        a2.second = ap[k].second.second;
                        a2.first = k;
                    }
                }
                if (map[bx][by][k])
                {
                    if (ap[k].second.second > b1.second)
                    {
                        b2.second = b1.second;
                        b2.first = b1.first;
                        b1.second = ap[k].second.second;
                        b1.first = k;
                    }
                    else if(ap[k].second.second > b2.second)
                    {
                        b2.second = ap[k].second.second;
                        b2.first = k;
                    }
                }
            }
         
            if (a1.first != -1 && b1.first != -1)
            {
                if (a1.first != b1.first) // 안겹치는경우
                {
                    charge_a += a1.second;
                    charge_b += b1.second;
                }
                else // 겹치는 경우
                {
                    //1. a만 하나
                    if (a2.first == -1 && b2.first != -1)
                    {
                        charge_a += a1.second;
                        charge_b += b2.second;
                    }
                    //2. b만 하나
                    else if (a2.first != -1 && b2.first == -1)
                    {
                        charge_a += a2.second;
                        charge_b += b1.second;
                    }
                    //3. 둘다 하나
                    else if(a2.first == -1 && b2.first == -1)
                    {
                        charge_a += a1.second / 2;
                        charge_b += b1.second / 2;
                    }
                    //4. 둘 다 두번째까지 같음.
                    else if(a2.first == b2.first)
                    {
                        charge_a += a1.second;
                        charge_b += b2.second;
                    }
                    //5. 두번째는 안겹치고 둘 다 존재하는 경우
                    else if(a2.second > b2.second)
                    {
                        charge_a += a2.second;
                        charge_b += b1.second;
                    }
                    else if(a2.second < b2.second)
                    {
                        charge_a += a1.second;
                        charge_b += b2.second;
                    }
                }
            }
            else
            {
                if (a1.first != -1)
                    charge_a += a1.second;
                else if (b1.first != -1)
                    charge_b += b1.second;
            }
            if(i == M)
                break;
            ax = ax + mx[move_a[i]];
            ay = ay + my[move_a[i]];
            bx = bx + mx[move_b[i]];
            by = by + my[move_b[i]];
            // cout<< " char a : " << charge_a << " char b : " << charge_b << endl;
            // cout << endl;
        }

        cout << "#" << t << " " << charge_a+charge_b <<  endl;
    }
}