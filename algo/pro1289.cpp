#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    bool check[100][100];
    memset(check,true, sizeof(check));
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    queue<pair<int, int>> q;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(picture[i][j] && check[i][j])
            {

                            // cout << "i " << i << " j " << j << endl;

                int size = 0;
                number_of_area++;
                q.push(make_pair(i, j));
                check[i][j] =false;

                while(!q.empty())
                {
                    int idx = q.front().first;
                    int idy = q.front().second;
                    q.pop();
                    size++;
                    for(int k=0; k<4; k++)
                    {
                        int ddx = idx + dx[k];
                        int ddy = idy + dy[k];
                        if(ddx>=0 && ddy >=0 && ddx<m && ddy<n)
                        if(check[ddx][ddy] && (picture[idx][idy] == picture[ddx][ddy]))
                        {
                            q.push(make_pair(ddx, ddy));
                            // cout << "i " << i << " j " << j <<" idx " << ddx << " idy " << ddy <<  endl;
                            check[ddx][ddy] =false;
                        }
                    }
                }
                if (max_size_of_one_area < size)
                    max_size_of_one_area = size;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    vector<int> answer(2);
    vector<vector<int>> picture = 	{{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, 
    {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    answer = solution(6, 4, picture);
    cout << "answer " << answer[0] <<  " " << answer[1] << endl;
    return 0;
}