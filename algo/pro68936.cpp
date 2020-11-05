#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = {0, 0, 1, 1};
int dy[4] = {1, 0, 0, 1};

vector<int> v(2);
vector<vector<int>> dfs(vector<vector<int>> arr);
vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;
    arr = dfs(arr);
    answer.push_back(v[0]);
    answer.push_back(v[1]);
    return answer;
}

vector<vector<int>> dfs(vector<vector<int>> arr)
{
    // cout << "==============="<<endl;
    // for(int i=0; i<arr.size(); i++)
    // {
    //     for(int j=0; j<arr[0].size(); j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
    vector<vector<int>> answer;
    if(arr.size() == 1)
    {
        if(arr[0][0] == 1)
            v[1]++;
        else if(arr[0][0] == 0)
            v[0]++;
        return answer;
    }
    else
    {
    for (int i = 0; i < arr.size() / 2; i++)
    {
        vector<int> tmp_vector;
        for (int j = 0; j < arr.size() / 2; j++)
        {
            vector<int> tmp(2);
            bool check = true;
            for (int k = 0; k < 4; k++)
            {
                if (arr[i*2 + dx[k]][j*2 + dy[k]] == -1)
                    check = false;
                else
                {
                    tmp[arr[i*2 + dx[k]][j*2 + dy[k]]]++;
                }
            }
            if(check) // 합치는 과정
            {
                if(tmp[0] == 4) 
                    tmp_vector.push_back(0);
                else if(tmp[1] == 4)
                    tmp_vector.push_back(1);
                else
                {
                    v[0] += tmp[0];
                    v[1] += tmp[1];
                    tmp_vector.push_back(-1);
                } 
            }
            else
            {
                v[0] += tmp[0];
                v[1] += tmp[1];
                tmp_vector.push_back(-1);
            }

        }
        answer.push_back(tmp_vector);
    }
    answer = dfs(answer);
    return answer;
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1}};
    // vector<vector<int>> arr = {{0, 1}, {1, 1}};
    vector<int> answer = solution(arr);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    return 0;
}