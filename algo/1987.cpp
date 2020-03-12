#include <iostream>
#include <vector>

using namespace std;
int bfs(int, int, int);
int ans=0;
char boad[20][20];
int check[30];
    int r, c;
int main()
{

    cin >>r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> boad[i][j];
    bfs(0,0,1);
    cout << ans;
    return 0;   
}

int bfs(int x, int y, int cnt)
{
    if(ans < cnt)
        ans = cnt;
    // cout << "cnt " << cnt << endl;
    //  cout << "ans " << ans << endl;
    // cout << " x " << x << " y " << y << endl;
    char alpha;
    int dx, dy;

        alpha = boad[x][y];
        check[alpha-'A'] = true;
        int shift_x[4] = {-1, 0, 1, 0};
        int shift_y[4] = { 0, 1, 0, -1};
        for(int i=0; i<4; i++)
        {
            dx = x + shift_x[i];
            dy = y + shift_y[i];
            if(dx>=0 && dy>=0 && dx<r && dy<c && !check[boad[dx][dy] - 'A'])
            {
                bfs(dx, dy, cnt+1);
                check[boad[dx][dy]-'A'] = false;
            }
        }
    return 0;  
}