#include <iostream>
using namespace std;
int change = 0;
bool check = false;

int main()
{
    int Test = 0;
    cin >> Test;
    for (int t = 1; t <= Test; t++)
    {
        int size = 0;
        int num[6] = {0, 0, 0, 0, 0, 0};
        int n;
        cin >> n;
        int tmp = n;
        cin >> change;
        while (tmp)
        {
            num[5 - size] = tmp % 10;
            tmp = tmp / 10;
            size++;
        }
        int start = 6 - size;

        // for (int i = start; i < 6; i++)
        //     cout << num[i] << " ";
        for (int i = start; i < 5; i++)
        {
            // cout << "change : " << change << endl;
        // for (int l = start; l < 6; l++)
            // cout << num[l] << " ";
            // cout << endl;


            //5번케이스 예외처리 -> 앞에는 숫자가 내림차순으로 존재, 뒤에는 같은숫자 연속인 경우.

            if (change == 0)
                break;
            int m = i;
            for (int j = i + 1; j < 6; j++)
            {
                if (num[i] == num[j])
                    check = true;
                if (num[m] <= num[j])
                    m = j;
            }
            if (m != i && num[m] != num[i]) // swap
            {
                // cout << "i " << i << " m " <<  m << endl;
                tmp = num[i];
                num[i] = num[m];
                num[m] = tmp;
                change--;
            }
        }

        while (change > 0)
        {
            change = change % 2;
            if (check)
                break;
            else
            {
                if (change) // 맨 끝자리 숫자 바꿈
                {
                    tmp = num[5];
                    num[5] = num[4];
                    num[4] = tmp;
                    change--;
                }
            }
        }
        cout <<"#"<<t<<" ";
        for(int i = start; i<6; i++)
            cout<<num[i];
        cout << endl;
    }
    return 0;
}
