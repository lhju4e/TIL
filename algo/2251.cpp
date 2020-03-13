#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<tuple<int, int, int>> q;
vector<int> v;
bool check_a[201];
bool check_b[201];
bool check_c[201];
int main()
{
    int max[3];
    cin >> max[0] >> max[1] >> max[2];
    int a = 0, b = 0, c = max[2];
    q.push(make_tuple(a, b, c));
    check_a[a] = true;
    check_b[b] = true;
    check_c[c] = true;

    while (!q.empty())
    {
        int bottle[3];
        tie(a, b, c) = q.front();
        tie(bottle[0], bottle[1], bottle[2]) = q.front();
        q.pop();
        if(a == 0)
            v.push_back(c);
        for (int i = 0; i < 3; i++)
        {
            tie(bottle[0], bottle[1], bottle[2]) = tie(a, b, c);
            if (bottle[i]) // 병이 채워져있으면
            {
                for (int j = 0; j < 3; j++)
                {
                    tie(bottle[0], bottle[1], bottle[2]) = tie(a, b, c);
                    if (i != j) // 다른 병들에 물을 부음
                    {
                        bottle[j] = bottle[j] + bottle[i];
                        bottle[i] = 0;
                        if (bottle[j] > max[j]) // 부은 병이 넘쳤을 때 처리
                        {
                            bottle[i] = bottle[j] - max[j];
                            bottle[j] = max[j];
                        }
                    }
                    if (!check_a[bottle[0]] || !check_b[bottle[1]] || !check_c[bottle[2]])
                    {
                        // cout << bottle[0] << " " << bottle[1] <<" " <<  bottle[2] << endl;
                        q.push(make_tuple(bottle[0], bottle[1], bottle[2]));
                        check_a[bottle[0]] = true;
                        check_b[bottle[1]] = true;
                        check_c[bottle[2]] = true;
                    }
                }
            }
        }
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    return 0;
}