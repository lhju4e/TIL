#include <iostream>
using namespace std;
void go(int, int);
void MOVE(int);
int MAX = 0;
int cnt = 0;
int n;
int MAP[20][20];  
int COPY[20][20];
int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin >> MAP[i][j];
            COPY[i][j] = MAP[i][j];
            if(MAX < MAP[i][j])
                MAX = MAP[i][j];
        }    
    for(int k=0; k<4; k++)
    {
        go(0, k);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                MAP[i][j] = COPY[i][j];
    }
    cout << MAX;
    return 0;
}

void MOVE(int b)
{
    if(b == 0) // 위
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n-1; j++)
            {
                
            }
                for(int k=j+1; k<n; k++)
            {
                if(MAP[j][i] == 0)
            }
    }
    else if(b == 1) // 오른쪽
    {

    }
    else if(b ==2) // 아래
    {

    }
    else // 왼쪽
    {

    }
}

void go(int a, int b)
{
    if(MAX < cnt)
        MAX = cnt;
    // cout << "=========="<<endl;
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<n; j++)
    //         cout << MAP[i][j] <<" ";
    //     cout << endl;
    // }
        
                    
    if (a == 5)
        return;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            COPY[i][j] = MAP[i][j];
    if(b == 0) // 위로 밀기
        for(int i=0; i<n; i++)
            for(int j=0; j<n-1; j++)
                if(MAP[j][i] == MAP[j+1][i])
                {
                    MAP[j][i] = MAP[j][i]*2;
                    if(cnt < MAP[j][i])
                        cnt = MAP[j][i];
                    MAP[j+1][i] = 0;
                }

    if(b == 1) // 오른쪽으로 밀기
        for(int i=0; i<n; i++)
            for(int j=n-1; j>0; j--)
                if(MAP[i][j] == MAP[i][j-1])
                {
                    MAP[i][j] = MAP[i][j]*2;
                    if(cnt < MAP[i][j])
                        cnt =  MAP[i][j];
                    MAP[i][j-1] = 0;
                }

    if(b==2) // 아래로 밀기
        for(int i=0; i<n; i++)
            for(int j=n-1; j>0; j--)
                if(MAP[j][i] == MAP[j-1][i])
                {
                    MAP[j][i] = MAP[j][i]*2;
                    if(cnt <  MAP[j][i])
                    cnt = MAP[j][i];
                    MAP[j-1][i] = 0;
                }
    if(b == 3) // 왼쪽으로 밀기
        for(int i=0; i<n; i++)
            for(int j=0; j<n-1; j++)
                if(MAP[i][j] == MAP[i][j+1])
                {
                    MAP[i][j] = MAP[i][j]*2;
                    if(cnt < MAP[i][j])
                    cnt = MAP[i][j];
                    MAP[i][j+1] = 0;
                }

    for(int k=0; k<4; k++)
    {
        go(a+1, k);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                MAP[i][j] = COPY[i][j];
    }
}