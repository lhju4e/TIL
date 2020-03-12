#include <iostream>
#include <vector>
using namespace std;
int sdo[10][10];
vector<pair<int, int>> v;
bool check(int, int);
bool func(int);
int main()
{
    int x, y;
    for(int i=1; i<10; i++)
    {
        for(int j=1; j<10; j++)
        {
            cin >> sdo[i][j];
            if(sdo[i][j] == 0)
                v.push_back(make_pair(i, j));
        }
    }
    func(0);
    return 0;
}

bool func(int idx)
{
    // cout << " idx " << idx << endl;
    if(idx == v.size())
    {
        for(int i=1; i<10; i++)
        {
            for(int j=1; j<10; j++)
                cout << sdo[i][j] << " ";
            cout << endl;
        }
        exit(0); 
        return true;
    }

    int x, y;
    x = v[idx].first;
    y = v[idx].second;
    for(int i=1; i<10; i++)
    {
        // cout << " x " << x << " y " << y << " i " << i << endl;
        sdo[x][y] = i;
        if(check(x, y))
        {
            func(idx+1);
            sdo[x][y] = 0;
        }
        else
            sdo[x][y] = 0;

    }
    return true;
}
bool check(int x, int y)
{

    for(int i=1; i<10; i++)
    {
        if(sdo[x][i] == sdo[x][y] && i!=y)
            return false;
    }
    // cout << "check 1" << endl;
    for(int i=1; i<10; i++)
    {
        if(sdo[i][y] == sdo[x][y] && i!=x)
            return false;
    }
        // cout << "check 2" << endl;

    int tx = (x-1)/3;
    int ty = (y-1)/3;
    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            // cout << sdo[tx*3 + i][ty*3 + j] << " ";
            // cout << "sdo[x][y]" << sdo[x][y] << " " ;
            if((sdo[tx*3 + i][ty*3 + j] == sdo[x][y]) && (tx*3 + i != x) && (ty*3 + j != y))
                return false;
        }
    }
        // cout << "true " << endl;

    return true;
}