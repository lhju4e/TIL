#include <string>
#include <vector>
#include <iostream>

using namespace std;
int tri_array[1000][1000];

vector<int> solution(int n) {
    vector<int> answer;
    int dir = 0;
    int i = -1;
    int j = 0;
    int m = 1;

    for (int k = n; k >= 1; k--)
    {
        for (int tmp = 0; tmp < k; tmp++, m++)
        {
            if(dir == 0) // 아래로 내려감
            {
                tri_array[++i][j] = m;
            }
            else if(dir == 1) // 오른쪽으로
            {
                tri_array[i][++j] = m;
            }
            else
            {
                tri_array[--i][--j] = m;
            }
            
        }
        dir++;
        dir = (int)(dir % 3);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if (tri_array[i][j])
                answer.push_back(tri_array[i][j]);
    }
    // for(int i=0; i<answer.size(); i++)
    //     cout << answer[i] << " ";

    // for(int i=0; i<=n; i++)
    // {
    //     for(int j=0; j<=n; j++)
    //         cout << tri_array[i][j] << " ";
    //     cout << endl;
    // }
    return answer;
}

int main()
{
    vector<int> answer;
    answer = solution(6);
    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << " "; 
    return 0;   
}