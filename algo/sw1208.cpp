#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    for (int t = 1; t <= 10; t++)
    {
        int num; // 덤프 횟수
        cin >> num;
        vector<int> box(100);
        for (int i = 0; i < 100; i++)
            cin >> box[i];
        sort(box.begin(), box.end());
        int tmp = 0;
        while (num)
        {
            // for (int i = 0; i < 100; i++)
            // cout << box[i] << " ";
            // cout << endl;
            box[99]--;
            box[0]++;
            for (int i = 0; i < 99; i++)
            {
                if(box[i] > box[i+1])
                {
                    tmp = box[i];
                    box[i] = box[i+1];
                    box[i+1] = tmp;
                }
                else
                    break;
            }
            for (int i = 99; i >= 1; i--)
            {
                if (box[i] < box[i - 1])
                {
                    tmp = box[i];
                    box[i] = box[i - 1];
                    box[i - 1] = tmp;
                }
                else
                    break;
            }
            // cout << box[99] - box[0] << endl;
            num--;
        }
        cout << "#"<<t<< " " << box[99] - box[0] << endl;
    }
}