#include <iostream>
using namespace std;
int a[100001];
int l[100001];
int r[100001];
int main()
{
    int n;
    int tmp=0;
    int tmp2 = 0;
    int m;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    l[1] = a[1];
    m = l[1];
    for(int i=2; i<=n; i++)
       l[i] = max(l[i-1] + a[i], a[i]);
    r[n] = a[n];
     for(int j=n-1; j>=1; j--)
        r[j] = max(r[j+1] + a[j], a[j]);
    for(int i=1; i<n; i++)
        if(m<l[i])
            m = l[i]; 
    // for(int i=1; i<=n; i++)
    //     cout << l[i] << " ";
    // cout << endl;
    // cout << "m " << m << endl;
    for(int i=1; i<=n; i++)
    {
       if(a[i] < 0)
       {
           if(i==1)
           {
               tmp=0;
               tmp2 = r[2];
           }
           if(i==n)
           {
               tmp=l[i-1];
               tmp2=0;
           }
           else
           {
            tmp = l[i-1];
            tmp2 = r[i+1];
           }
       }
       if(m < tmp+tmp2)
        m = tmp+ tmp2;
    }
    cout << m;
    return 0;
}