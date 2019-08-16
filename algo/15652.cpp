#include <stdio.h>
void go(int, int , int , int);
int num[10] = {0};

int main()
{
    int n, m;
    int start = 1;
    scanf("%d %d", &n, &m);
    go(0, 1, n, m);
}
void go(int index, int start, int n, int m)
{
    //멈추는 조건 - 이미 원하는 만큼 뽑았을 때
    if(index == m)
    {
        for(int i=0; i<m; i++)
            printf("%d ", num[i]);
        printf("\n");
        return ;
    }
    for(int i=start; i<=n; i++)
    {

        num[index] = i;
        //1 2, 1 3, 1 4, 2 3, 등.. 앞 숫자보다 항상 같거나 높음   
        start = i;  
        go(index+1, start, n, m);

    }
}
