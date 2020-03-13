#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    int ans = 0; 
    for(int i=0; i<5; i++)
    {

            cout << "i " << i << endl;
            cout << "pow(10, i) " << pow(10, i) << endl;
            int c = pow(10, i);
            cout << "i * pow(10, i) " << i * pow(10, i) << endl;
            int b = i * pow(10, i);
            ans += (int)(i * pow(10, i));
            printf("int print : %d\n", ans);
            cout << "ans " << ans << endl;   
            cout << "-----" << endl;
    }
    cout << ans;
    return 0;
}