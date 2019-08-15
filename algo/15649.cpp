#include <stdio.h>
void go(int , int , int);
int num[10] = {0};
int c[10] = {0};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    go(0, n, m);
}
void go(int index, int n, int m)
{
    //멈추는 조건 - 이미 원하는 만큼 뽑았을 때
    if(index == m)
    {
        for(int i=0; i<m; i++)
            printf("%d ", num[i]);
        printf("\n");
        return ;
    }
    for(int i=1; i<=n; i++)
    {
        if(!c[i]) // i가 아직 사용되지 않았다면
        {
            num[index] = i;
            c[i] = 1;        
            go(index+1, n, m);
            c[i] = 0;
        }
    }
}
