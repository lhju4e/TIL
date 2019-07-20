#include <iostream>
using namespace std;
int m = -1;
void go(int, int, int, int*, int*);
int main()
{
    int n;
    cin >> n;
    int t[15] ={0,}; // 걸리는 날짜
    int p[15]={0,}; //벌ㄹ리는 돈
    for(int i=0; i<n; i++)
        cin>>t[i]>>p[i];
    go(0, 0, n, p, t);
    cout<<m;
    return 0;
}

void go(int day, int sum, int n, int *p, int *t)
{
    //넘어가서 끝나야 하는 경우
    if(day>n)
        return;
    //정답을 찾은 경우
    if(day == n)
    {
        if(sum>m)
            m = sum;
        return;
    }
    //계속 진행하는 경우
    go(day+t[day], sum+p[day], n, p, t );//오늘상담을 하는경우
    go(day+1, sum, n, p, t);//안하는 경우
}