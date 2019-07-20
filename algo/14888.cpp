#include <stdio.h>
#include <math.h>
int go(int, int *, int , int , int ,  int , int , int );
int max = -pow(10, 9) -1, min = pow(10, 9) +1; 
int main()
{
    int n=0;
    int a[100]={0,};
    int plus, minus, mul, divi;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    scanf("%d %d %d %d", &plus, &minus, &mul, &divi);
    go(n, a, 1, a[0], plus, minus, mul, divi );
    printf("%d\n%d", max, min);
}

int go( int n,int *a, int index, int result, int plus, int minus, int mul, int divi)
{
    if(plus<0 || minus<0 || mul <0 || divi<0 ) //함수를 더 이상 사용하지 못하는 경우
         return 0;
    if(index == n) //함수가 끝난 경우
    {
        if(result<min)
            min = result;
        if(result>max)
            max = result;
        return 0;
    }

    else //함수 계속 진행
    {
        go(n, a, index+1, result+a[index], plus-1, minus, mul, divi); //plus
        go(n, a, index+1, result-a[index], plus, minus-1, mul, divi);//minus
        go(n, a, index+1, result*a[index], plus, minus, mul-1, divi);//*
        go(n, a, index+1, result/a[index], plus, minus, mul, divi-1);// %
    }
}