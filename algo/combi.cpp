#include <iostream>
#include <vector>
using namespace std;
vector<int> result;
int n = 5;
int arr[5] = {1, 2, 3, 4, 5};
int dfs(int, int);
int main()
{
    dfs(0, 3);
    return 0;
}

int dfs(int idx, int r)
{
    if(idx>5)
        return 0;
    if(result.size()==r)
    {
        for(int i=0; i<r; i++)
            cout << result[i] << " ";
        cout << endl;
    }
    else
    {
        result.push_back(arr[idx]);
        dfs(idx+1, r);
        result.pop_back();
        dfs(idx+1, r);
    }
}