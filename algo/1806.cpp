#include <iostream>
using namespace std;
int a[100001];
int ans = 0;
// void func(int);
int n, s;
int main()
{
    int MAX = 0;
    int max_index = -1;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (MAX < a[i])
        {
            MAX = a[i];
            max_index = i;
            if (MAX >= s)
            {
                cout << 1;
                return 0;
            }
        }
    }
    int SUM = MAX;
    ans = 1;
    bool i_check = true;
    bool j_check = true;
    int i = max_index - 1;
    int j = max_index + 1;
    while (i_check || j_check)
    {
        cout << SUM << endl;
        if (i == -1)
            i_check = false;
        if (j == n)
            j_check = false;
        if (i_check && j_check) // i랑 j가 범위 안에 있는 경우
        {
            if(a[i] > a[j])
            {
                SUM += a[i];
                i--;
            }
            else
            {
                SUM += a[j];
                j++;
            }         
        }               // 서로 비교해서 높은 값 더해줌
        else if (i_check)  // i만 범위 안
        {
            SUM += a[i];
            i--;
        }
        else if (j_check) 
        {
            SUM += a[j];
            j++;
        }
            ans++;
        if(SUM >= s)
        {
            cout << SUM << endl;
            cout << ans;
            return 0;
        }
    }

    // func(1);
    cout << 0;
    return 0;
}

//시간초과
// void func(int num)
// {
//     if(num == n)
//         return;
//     int sum = 0;
//     for(int i=0; i<num; i++)
//     {
//         sum += a[i];
//         if(sum > s)
//         {
//             ans = num;
//             return;
//         }
//     }

//     for(int i=0; i<n-num; i++)
//     {
//         sum = sum - a[i];
//         sum = sum + a[i + num];
//         if(sum > s)
//         {
//             ans = num;
//             return;
//         }
//     }
//     func(num+1);
// }