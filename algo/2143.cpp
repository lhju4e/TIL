#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[1001];
int b[1001];
    vector<int> la;
    vector<int> lb;
int main()
{
        int t, n, m;
        long long cnt=0;
    // cin >> t >> n;
    scanf("%d %d", &t, &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
        // cin >> a[i];
    // cin >> m;
    scanf("%d", &m);
    for(int i=0; i<m; i++)
        scanf("%d", &b[i]);
        // cin >> b[i];

    for(int i=0; i<n; i++)
    {
        int sum = a[i];
        la.push_back(sum);
        for(int j=i+1; j<n; j++)
        {
            sum += a[j];
            la.push_back(sum);
        }
    }
    for(int i=0; i<m; i++)
    {
        int sum = b[i];
        lb.push_back(sum);
        for(int j=i+1; j<m; j++)
        {
            sum += b[j];
            lb.push_back(sum);
        }
    }
    sort(la.begin(), la.end());  
    sort(lb.begin(), lb.end());

//     for(int i=0; i<la.size(); i++)
//         cout << la[i] << " ";
//     cout << endl;
//   for(int i=0; i<lb.size(); i++)
//         cout << lb[i] << " ";
//         cout << endl;
    int i=0;
    int j=lb.size()-1;
    while(i < la.size() && j >=0)
    {
        int s = la[i] + lb[j];
        // cout << "i " << i << " j " << j << " s " << s << endl;
        if(s == t)
        {
            long long ac=1;
            long long bc=1;

            while(i+1 < la.size() && la[i] == la[i+1])
            {
                ac++;
                i++;
            }
            i++;
            while(j-1 >=0 && lb[j] == lb[j-1])
            {
                bc++;
                j--;
            }
            j--;
            cnt += ac*bc;
            // cout << "ac " << ac << " bc " << bc << " cnt " << cnt<<endl;
        }
        else if(s < t)
            i++;
        else
            j--;
    //    cout << "-i " << i << " j " << j << " s " << s << endl; 
    }
    // cout << cnt;
    printf("%lld", cnt);
    return 0;
}