#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
        bool check[102][102];
        char MAP[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++)
    {
        multimap<char, pair<int, int>> m;
        int cnt = 0;
        vector<char> key;
        char tmp;
        memset(check, 0, sizeof(check));
        memset(MAP, 0, sizeof(MAP));
        deque<pair<int, int>> q;
        int h, w;
        scanf("%d %d", &h, &w);
        scanf("%c", &tmp);
        for (int i = 0; i <= w + 1; i++)
        {
            MAP[0][i] = '.';
            MAP[h + 1][i] = '.';
        }
        for (int i = 0; i <= h + 1; i++)
        {
            MAP[i][0] = '.';
            MAP[i][w + 1] = '.';
        }
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
                scanf("%c", &MAP[i][j]);
            scanf("%c", &tmp);
        }

        // for (int i = 0; i <= h + 1; i++)
        // {
        //     for (int j = 0; j <= w + 1; j++)
        //         printf("%c", MAP[i][j]);
        //     printf("\n");
        // }
        q.push_back(make_pair(0, 0));
        check[0][0] = true;

        while (1)
        {
            char a;
            scanf("%c", &a);
            // cout << a << endl;
            if (a == '\n')
                break;
            key.push_back(a);
        }

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();

            for(int i=0; i<4; i++)
            {
                int mx = x + dx[i];
                int my = y + dy[i];
                bool back = true;
                if(mx>=0 && mx <= h+1 && my>=0 && my<=w+1 && MAP[mx][my]!='*' && !check[mx][my])
                {
                    check[mx][my] = true;
                    if(MAP[mx][my] >= 'A' && MAP[mx][my] <= 'Z')
                    {
                        for(int j=0; j<key.size(); j++)
                        {
                            if(key[j] - 'a' == MAP[mx][my] - 'A')
                                back = false; // 문에 맞는 key를 찾으면
                        }
                    if(back)
                            m.insert(make_pair(MAP[mx][my], make_pair(mx, my))); //key를 못찾았으면 일단 map에다가 넣어둠.
                    else
                        q.push_front(make_pair(mx, my));
                    }
                    else
                    {
                        q.push_front(make_pair(mx, my));
                        if(MAP[mx][my] == '$')
                            cnt++;
                        else if(MAP[mx][my] >= 'a' && MAP[mx][my] <= 'z')
                        {
                            key.push_back(MAP[mx][my]);
                            char tmp = MAP[mx][my]-'a'+'A';
                            if(m.count(tmp))
                            {
                                for(auto iter= m.equal_range(tmp).first; iter!=m.equal_range(tmp).second; iter++)
                                {
                               int a = iter->second.first;
                                int b = iter->second.second;
                                q.push_front(make_pair(a, b));
                                }
 
                            }
                        }
                           
                    }

                }
            }
        }
    printf("%d\n", cnt);
        // for (int i = 0; i <= h + 1; i++)
        // {
        //     for (int j = 0; j <= w + 1; j++)
        //         printf("%d", check[i][j]);
        //     printf("\n");
        // }

    }
    return 0;
}