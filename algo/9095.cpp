#include <stdio.h>
int go( int, int);
int count;
int main()
{
    int t, n;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        count = 0;
        scanf("%d", &n);
        go(0, n);
        printf("%d\n", count);
    }
}
int go(int sum, int goal) // 지금까지 더한 숫자들으 ㅣ합 : sum, 목표 합(n) : goal
{
    if(sum>goal) // 더합 합이 목표 합보다 크면 끝
        return 0;
    else if(sum == goal) // 목표를 중촉했다면
        {
            count++; // 경우의 수 증가
            return 0; // 끝내기
        }
    else{ //계속 이어가는 경우
        go(sum+1, goal); //1을 더한다
        go(sum+2, goal); //2를 더한다
        go(sum+3, goal); //3을 더한다
    }
}