#include <iostream>
#include <string>
using namespace std;
string word[50];
bool check[26];
void combi(int, int);
int n, k;
int cnt = 0;
int mm = 0;
int main()
{
    string tmp;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        word[i] = tmp.substr(4, tmp.find("tica") - 4);
    }

    k = k - 5;

    if (k < 0)
    {
        std::cout << 0;
        return 0;
    }
    if (k == 21)
    {
        std::cout << n;
        return 0;
    }

    check['a'-'a'] = true;
    check['c' - 'a'] = true;
    check['t' - 'a'] = true;
    check['n' - 'a'] = true;
    check['i' - 'a'] = true;
    combi(0, 0);

    std::cout << mm;
    return 0;
}

void combi(int idx, int m) // 현재 뽑은 수 인덱스, 현재까지 뽑은 갯수
{
    if (m == k) // 다 뽑았으면
    {
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            bool word_check = false;
            for (int j = 0; j < word[i].length(); j++)
            {
                // std::cout << word[i][j] << " " << check[word[i][j]-'a'] << endl;
                if (!check[word[i][j] - 'a'])
                    word_check = true;
            }
            if (!word_check)
            {
                cnt++;
            }
        }
        if (cnt > mm)
            mm = cnt;
        return;
    }
    for (int i = idx; i <26; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            combi(i, m + 1);
            check[i] = false;
            check[0] = true;
            check['c' - 'a'] = true;
            check['t' - 'a'] = true;
            check['n' - 'a'] = true;
            check['i' - 'a'] = true;
        }
    }
}