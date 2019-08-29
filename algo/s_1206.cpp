#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int wid[1000] = {0,};
    int leng = 0;
    int a, b= 0;
    int result = 0;
	for(int i=1; i<11; i++)
    {
        scanf("%d", &leng);
        for(int i=0; i<leng; i++)
            scanf("%d", &wid[i]);
        for(int i=2; i<leng-2; i++)
        {
            if(wid[i]<wid[i-1] || wid[i]<wid[i-2])
                continue;
            if(wid[i]<wid[i+1] || wid[i]<wid[i+2])
                continue;
            a = max(wid[i-1], wid[i-2]);
            b = max(wid[i+1], wid[i+2]);
            result += (wid[i] - max(a, b));
            i += 1;
            a = 0; b = 0;
        }
        printf("#%d %d\n", i, result);
        result = 0;
    }
    return 0;
}