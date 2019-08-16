#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
void go(int, vector<int> & , int);
int num[10] = {0}; // 결과 순열
int cnt[10001] = {0,}; // 몇 개인지

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> n_arr(n); // 들어오는 값
    for(int i=0; i<n; i++)
    { // ex. 1이 여러개 들어오면 cnt[1] 이 1보다 높은 숫자
        scanf("%d", &n_arr[i]);
        cnt[n_arr[i]]++;
    }
    //중복제거 및 정렬
    sort(n_arr.begin(), n_arr.end());
    n_arr.erase(unique(n_arr.begin(), n_arr.end()), n_arr.end());
    go(0, n_arr, m);
}
void go(int index, vector <int>& n_arr, int m)
{
    //멈추는 조건 - 이미 원하는 만큼 뽑았을 때
    if(index == m)
    {
        for(int i=0; i<m; i++)
            printf("%d ", num[i]);
        printf("\n");
        return ;
    }
    for(int i=0; i<n_arr.size(); i++)
    {
        if(cnt[n_arr[i]]) //i번째에 있는 수가 존재하는지
        {
            num[index] = n_arr[i]; 
            cnt[n_arr[i]] -- ;
            go(index+1, n_arr, m);
            cnt[n_arr[i]] ++ ;
        }
    }
}