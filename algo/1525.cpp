#include <iostream>
#include <queue>
using namespace std;
bool check[900000];
int p2int(int puzzle[3][3]);
int pow(int x, int y)
{
    int ret = 1;
    for(int i=0; i<y; i++)
        ret = ret * x;
    return ret;
}

int main()
{
    int puzzle[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin >> puzzle[i][j];
    queue<int> q;
    int a = p2int(puzzle);
    q.push(a);
    check[a] = true;
    while(!q.empty())
    {
        
    }


    return 0;
}

int p2int(int puzzle[3][3])
{
    int ret = 0;
    for(int j=0; j<3; j++)
        for(int i=0; i<3; i++)
            ret += pow(10, 8-i-j*3) * puzzle[j][i];
    return ret;
}