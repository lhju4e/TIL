#include <iostream>
using namespace std;
void combi(int, int);
bool check[10];
int cnt = 0;
int a[10];
int n, m;
int main()
{
    cin >> n >> m; // n개의 수에서 m개를 뽑는 조합
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        combi(i, 0);
        check[i] = false;
    }
    cout << endl << cnt;
    return 0;
}

void combi(int idx, int k) // 현재 뽑은 수 인덱스, 현재까지 뽑은 갯수
{
    check[idx] = true; // 뽑은 수는 check로 표시해줌
    if (k == m - 1) // 다 뽑았으면
    {
        for (int i = 0; i < n; i++)
            cout << check[i]; // 뽑은 숫자열 출력
        cout << endl;
        cnt++; // 총 뽑은 갯수
        return;
    }
    for (int i = idx + 1; i < n; i++)
    {
        combi(i, k + 1); // 위에서 하나 뽑았으니까 k+1해줌.
        check[i] = false;
    }
}