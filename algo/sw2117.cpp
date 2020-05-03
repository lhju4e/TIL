#include <iostream>
using namespace std;
int MAP[20][20];
int N, M;
int service(int);
int main()
{
    int test;
    cin >> test;
    for(int t=1; t<=test; t++)
    {
        int cost = 0;
        int house = 0;
        cin >> N >> M;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> MAP[i][j];

        for(int k=N+1; k>=1; k--)
        {
            // cout << " k " << k << endl;
            house = service(k);
            cost = k*k + (k-1)*(k-1);
            cost = house*M - cost;
            if(cost >= 0)
            {
                // cout << "cost " << cost << endl;
                break;
            }
                // break;
        }
        cout << "#" << t << " " <<house <<endl;
    }
}

int service(int k)
{
    int cnt = 0;
    int MAX = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cnt = 0;
            // cout << "=====i " << i << " j ======="<< j << endl;
            for(int a = 0; a<k; a++)
            {
                int x = i - a;
                int y = j - (k - a - 1);
                for(int q=0; q<2*a+1; q++)
                {
                    if(x+q >=0 && y>=0 && x+q < N && y < N)
                    {
                        // cout << "X " << x+q << " Y " << y << endl; 
                        if(MAP[x+q][y])
                            cnt++;
                    }
                }
            }
            for(int a = 0; a<=k-2; a++)
            {
                int x = i - a;
                int y = j + (k - a - 1);
                for(int q=0; q<2*a+1; q++)
                {
                    if(x+q >=0 && y>=0 && x+q < N && y < N)
                    {
                        // cout << "X " << x+q << " Y " << y << endl; 
                        if(MAP[x+q][y])
                            cnt++;
                    }
                }
            }
            // cout << "cnt " << cnt << endl;
            if(cnt > MAX)
                MAX = cnt;
        }
    }
    // cout << "MAX " << MAX << endl;
    return MAX;
}