#include <iostream>
using namespace std;
int go(int index, int *a, int n, int sum, int s);
int cnt;
int main()
{
    int n, s=0;
    int a[20] = {0,};
    cin >>n>>s;
    for(int i=0; i<n; i++)
        cin >> a[i];
    go(0, a, n, 0, s);
    if(s == 0) //s가 0인 경우 공집합을 빼줘야함.
        cnt--;
    cout<<cnt;
    return 0;
}
int go(int index, int *a, int n, int sum, int s)
{
    //더 이상 못찾는 경우
    if(index == n && sum != s)
        return 0;
    //답을 찾은 경우
    if(index == n && sum == s)
    {
        cnt++;
        return 1;
    }
    //계속 찾는 경우
    go(index+1, a, n, sum+a[index], s);
    go(index+1, a, n, sum, s);
}