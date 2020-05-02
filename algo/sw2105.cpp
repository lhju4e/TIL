#include <iostream>
#include <string.h>
using namespace std;
int MAP[20][20];
bool check[101];
int n;
int dfs(int, int);
int main()
{
    int test;
    cin >> test;

    for (int t = 1; t <= test; t++)
    {
        int MAX = 0;
        int ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> MAP[i][j];

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                ans = dfs(i, j);
                if (ans > MAX)
                    MAX = ans;
            }
            if (MAX >= (n - (i + 1)) * 2)
                break;
        }
  
        if (MAX == 0)
            MAX = -1;
        else
            MAX = MAX * 2;
        cout << "#" << t << " " << MAX << endl;
    }
}

int dfs(int i, int j)
{
    bool go = true;
    int a = i;
    int b = j;
    int MAX = 0;
    int ans1 = 0;
    int ans2 = 0;
    memset(check, 0, sizeof(check));
    while (a < n && b < n)
    {
        go = true;
        if (!check[MAP[a][b]])
            check[MAP[a][b]] = true;
        else
        {
            go = false;
            check[MAP[a][b]] = false;
            break;
        }

        ans1++;
        a++;
        b++;
        int a2 = a;
        int b2 = b;
        while (a2 < n && b2 >= 0)
        {
            if (!check[MAP[a2][b2]])
                check[MAP[a2][b2]] = true;
            else
            {
                go = false;
                            check[MAP[a2][b2]] = false;

                break;
            }

            ans2++;
            a2++;
            b2--;
            int a3 = a2;
            int b3 = b2;
            for (int i = 0; i < ans1; i++)
            {
                if (a3 >= 0 && b3 >= 0)
                {
                    if (!check[MAP[a3][b3]])
                        check[MAP[a3][b3]] = true;
                    else
                    {
                        go = false;
                                    check[MAP[a3][b3]] = false;

                        break;
                    }
                }
                else
                {
                    go = false;
                                check[MAP[a3][b3]] = false;

                    break;
                }
                a3--;
                b3--;
            }
            for (int i = 0; i < ans2; i++)
            {
                if (!check[MAP[a3][b3]])
                    check[MAP[a3][b3]] = true;
                else
                {
                    go = false;
                                check[MAP[a3][b3]] = false;

                    break;
                }
                a3--;
                b3++;
            }
            if (go == true)
            {
                if (MAX < ans1 + ans2)
                    MAX = ans1 + ans2;
            }
        }
    }
    return MAX;
}