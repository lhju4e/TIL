#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string road, int n)
{
    bool check = false; // 1인지 체크.
    char pre = road[0];
    vector<int> v;    // 1개수, 0개수.
    vector<int> zero; // 0들이 있는 인덱스.
    if (pre == '1')
    {
        check = true;
    }
    int cnt = 1;
    for (int i = 1; i < road.size(); i++)
    {
        if (pre == road[i]) // 이전거랑 문자가 같으면
        {
            cnt++;
        }
        else
        {
            if (check) // 이전거까지가 1이었다면
            {
                v.push_back(cnt);
                check = false;
            }
            else // 이전까지가 0이었다면
            {
                v.push_back(cnt);
                zero.push_back(v.size() - 1);
                check = true;
            }
            cnt = 1;
        }
        pre = road[i];
    }
    if (check) // 이전거까지가 1이었다면
    {
        v.push_back(cnt);
    }
    else // 이전까지가 0이었다면
    {
        v.push_back(cnt);
        zero.push_back(v.size() - 1);
    }
    //     for (int i = 0; i < zero.size(); i++)
    // {
    //     cout << zero[i] << " ";
    // }
    // cout << endl;

    int answer = 0;
    cnt = 0;
    for (int i = 0; i < zero.size(); i++)
    {
        cnt += v[zero[i]];
    }
    if (cnt <= n)
    {
        for (int i = 0; i < v.size(); i++)
            answer += v[i];
        return answer;
    }

    for (int i = 0; i < zero.size(); i++)
    {
        cnt = 0;
        int broken = 0;
        for (int j = i; j < zero.size(); j++)
        {
            // cout << "========"<< i << j <<endl;
            broken += v[zero[j]];
            if (broken > n)
            {
                // cout << "b " << broken << endl;
                // cout <<"k " << zero[i]-1 << endl;
                int k = zero[i]-1;
                if(k <0)
                    k = 0;
                for (; k < zero[j]; k++)
                {
                    cnt += v[k];
                }
                broken -= v[zero[j]];
                // cout << "broken " << broken << endl;
                cnt += (n - broken);
                // cout << "cnt " << cnt << endl;
                break;
            }
            else if(broken == n)
            {
                int k = zero[i]-1;
                if(k <0)
                    k = 0;
                for (; k <= zero[j]; k++)
                {
                    cnt += v[k];
                }
                if(zero[j]+1 < v.size())
                    cnt += v[zero[j]+1];
                // cout << "cnt " << cnt << endl;
                break;
            }

        }
        if (cnt > answer)
            answer = cnt;
    }

    return answer;
}

int main()
{
    string road = "111011110011111011111100011111";
    cout << solution(road, 4);
    return 0;
}