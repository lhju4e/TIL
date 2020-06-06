#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double rounding(double x)
{
    x = x * 100;
    x = round(x);
    x = x / 100;
    return x;
}

int main()
{
    vector<double> L;
    int N, K;
    cin >> N >> K;
    double tmp;
    double min =0, max=0;
    for(int i=0; i<N; i++)
    {
        cin >> tmp;
        L.push_back(tmp);
        if(tmp > max)
            max = tmp;
    }
    while(rounding(min) != rounding(max))
    {
        int cnt = 0;
        double len = (min + max) / 2;
        for(int i=0; i<N; i++)
        {
            cnt += floor(L[i] / len);
        }
        if(cnt >= K)
            min = len;
        else
            max = len;
    }
    cout << fixed;
    cout.precision(2);
    cout << rounding(max) << endl;
    return 0;
}