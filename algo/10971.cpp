#include <stdio.h>
#include <algorithm>
int main()
{
    int MAX = 10000001; //최대값을 항상 신경쓰기
    int n, cnt=0, min=MAX;
    scanf("%d", &n);
    int a[10] = {0};
    for(int i=0; i<n; i++)
        a[i] = i;
    int w[10][10] = {0};
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &w[i][j]);
    std::sort(a, a+n);
    do{
        if((w[a[0]][a[1]]!=0) && (w[a[n-1]][a[0]]!=0)) // 가는 길과 오는 길이 둘 다 존재하면
        {
            cnt = w[a[0]][a[1]] + w[a[n-1]][a[0]]; //비용 넣어주고
            for(int i=1; i<n-1; i++) //중간비용 계산
            {
                if( w[a[i]][a[i+1]] != 0)
                    cnt += w[a[i]][a[i+1]];
                else // 중간에 길이 없다면
                {
                    cnt = MAX;
                    break;
                }
            }
            if(cnt<min)
                min = cnt;
            cnt = 0;
        }
    }while(std::next_permutation(a+1, a+n));
    printf("%d", min);
    return 0;
}