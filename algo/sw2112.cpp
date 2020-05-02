#include <iostream>
using namespace std;
bool film[13][20];
bool COPY[13][20];
bool pass();
int D, W, K;
bool swap(int, int, int);
int main()
{
    int test;
    int ans = 0;
    cin >> test;
    for(int t=1; t<=test; t++)
    {
        cin >> D >> W >> K;
        for(int i=0; i<D; i++)
            for(int j=0; j<W; j++)
                {cin >> film[i][j];
                    COPY[i][j] = film[i][j];
                }
        if(pass())
            ans = 0;
        else
        {
            // cout << "else" << endl;
            for(int k=1; k<=D; k++)
            {
                for(int i=0; i<D; i++)
                    for(int j=0; j<W; j++)
                        COPY[i][j] = film[i][j];
                // cout << "k " << k << endl;
                if(swap(0, 0, k))
                {
                    ans = k;
                    break;
                }         
            }
        }
        
        cout << "#"<<t<< " " <<ans <<  endl;
    }
    return 0;
}

bool swap(int curr, int cnt, int fin)//첫번째 : 세로줄. 두번째 : 카운트. 세번째 : 종료조건
{
    bool ret = false;
    if(cnt == fin)
    {
        // for(int i=0; i<D; i++)
        //     {for(int j=0; j<W; j++)
        //         cout << COPY[i][j];
        //         cout << endl;}
        // cout << endl;
        if(pass())
            {
                // cout << "pass" << endl;
                return true;}
        else return false;
    }
        
    for(int a=curr; a<D; a++)
    {
        for(int i=0; i<W; i++) //A로 변경
            COPY[a][i] =0;
        if(swap(a+1, cnt+1, fin))
            ret = true;
        for(int i=0; i<W; i++) // B로 변경
            COPY[a][i] = 1;
        if(swap(a+1, cnt+1, fin))
            ret = true;
        for(int i=0; i<W; i++)
            COPY[a][i] = film[a][i];
    }
    return ret;
}

bool pass()
{
    for(int i=0; i<W; i++)
    {
        bool check = true;
        bool before;
        int j = 0;
        while(j<D-K+1)
        {   
            // cout << "j " << j << endl;
            check = true;
            before = COPY[j][i];
            for(int k=j+1; k<j+K; k++) // 슬라이딩 윈도우로 검사.
            {
                if(before != COPY[k][i])
                {
                    check = false; // 이전 값이랑 다르면 false 후 리턴
                    j = k; // 검사했던 값부터 검사.
                    break;
                }
            } 
            if(check)
                break;         
        }
        if(!check)
            return false;
    }
    return true;
}

