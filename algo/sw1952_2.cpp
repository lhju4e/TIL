#include<iostream>
using namespace std;
int dfs(int, int);
int month[12];
int cost[4]; // 일. 1달. 3달. 년.

int main()
{
    int Test;
    cin >> Test;
    for(int t=1; t<=Test; t++)
    {

        for(int i=0; i<4; i++)
            cin >> cost[i];

        for(int i=0; i<12; i++)
           cin >> month[i];
        int ans = dfs(0, 0);
        if(ans > cost[3])
            ans = cost[3];
        cout << "#" << t << " " << ans << endl;
    }
}

int dfs(int time, int pay)
{
    if(time>=12) // return
    {
        return pay;
    }
    // int money = cost[0] * month[time];
    // if(money > cost[1])
    //     money = cost[1];
    int a = dfs(time+1, pay + cost[1]);
    int b = dfs(time+3, pay + cost[2]);
    int c = dfs(time+1, pay + cost[0] * month[time]);
    if(a < b)
    {
        if (a < c)
            return a;
        else
            return c;
    }
    else
    {
        if(b < c)
            return b;
        else
            return c;  
    }
    
}