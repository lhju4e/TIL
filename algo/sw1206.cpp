#include <iostream>
#include <string.h>
using namespace std;
int map[1001];
int main()
{
    for(int t=1; t<=10; t++)
    {
        memset(map, 0, sizeof(map));
        int n;
        cin >> n;
        int ans = 0;
        for(int i=0; i<n; i++)
            cin >> map[i];

        int k = 2;
        while(k < n -2)
        {
            bool check = true;
            int min = 300;
            for(int i = k-2; i<k; i++) // 왼쪽체크
            {
                if(map[k] <= map[i])
                {
                    check = false;
                    k += 1;
                    break;
                }
                int m = map[k] - map[i];
                if(m < min)
                    min = m;
            }
            if(!check)
                continue;
            else // 오른쪽 체크
            {
                check = true;
                for(int i = k+1; i<k+3; i++) 
            {
                if(map[k] <= map[i])
                {
                    k = i;
                    check = false;
                    break;
                }
                int m = map[k] - map[i];
                if(m < min)
                    min = m;

            }
            }
            if(!check)
                continue;
            k += 1;
            if(min != 300)
            {
                ans += min;
            }
            
        }
        cout << "#"<<t<< " " << ans<<endl;
    }
    return 0;
}