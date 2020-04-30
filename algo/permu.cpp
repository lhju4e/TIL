#include <iostream>
#include <vector>
using namespace std;
vector<int> result;
int n = 3;
bool visit[5];
int arr[5] = {1, 2, 3, 4, 5};
int dfs(int);
int main()
{
    dfs(2);
    return 0;
}

int dfs(int r)
{
    if(result.size() == r)
    {
        for(int i=0; i<r; i++)
            cout << result[i] << " ";
        cout << endl;
        // return 1;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            // if(visit[i]) continue; // 중복순열인지 아닌지.
            result.push_back(arr[i]);
            visit[i] = true;
            dfs(r);
            result.pop_back();
            visit[i] = false;
        }
    }
}