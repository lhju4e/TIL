#include<iostream>
using namespace std;

int main()
{
    int Test;
    cin >> Test;
    for(int t=1; t<=Test; t++)
    {
        int tmp = 0;
        int ans = 0;
        int min = 5000;
        int cost[4]; // 일. 1달. 3달. 년.
        int check[12];
        bool month3[10];
        for(int i=0; i<4; i++)
            cin >> cost[i];
        int month[12];
        for(int i=0; i<12; i++)
           cin >> month[i];
        
        for(int i=0; i<10; i++) // 변수 초기화.
            month3[i] = false;

        // 1. 1달과 1일 비교.
        for(int i=0; i<12; i++)
        {
            check[i] = (cost[0] * month[i]); // 일권이 낫다.
        
           if(check[i] > cost[1]) //1달이 낫다.
            check[i] = cost[1];
            ans += check[i];
        }       
        if(min > ans)
            min = ans;

        //2. 현재 값과 3달씩 끊은 값 비교.
        for(int i=0; i<10 ; i++)
        {
            tmp = check[i] + check[i+1] + check[i+2];
            if(cost[2] < tmp)
                month3[i] = true;
        }

        for(int i=0; i<3; i++)
        {
            int k = 0;
            ans = 0;
            for(; k<i; k++) // 앞부분 - 1월, 2월 가격보다 3달권이 싸다면.
                ans += check[k];
            if(ans > cost[2])
                ans = cost[2];
            //  cout << "i " <<i << " ans " << ans << endl;

            for(int j=i; j<10; j = j+3)
            {
                if(month3[j])
                    ans += cost[2];
                else
                    ans += check[j] + check[j+1] + check[j+2];
                k = j+3;
            }
            // cout << "k " <<k << " ans " << ans << endl;

            //뒷부분. 11, 12월 마찬가지.
            tmp = 0;
            for(; k<12; k++)
                tmp += check[k];
            if(tmp > cost[2])
                tmp = cost[2];
            // cout <<  " tmp " << tmp << endl;

            ans += tmp;  
        
            if(min > ans)
            min = ans;
        }

        //1년권 비교.
        ans = cost[3];
        if(min > ans)
            min = ans;

       cout <<  "#" << t << " " << min << endl;
    }
    return 0;
}