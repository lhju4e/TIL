#include <iostream>
#include <string>
using namespace std;

//cin말고 scanf써야 백준에서 맞음
//왜지
int main()
{
    int m, s=0;
    cin >> m;
    char in[11];
    int a;
    int tmp = 0;
    for(int i=0; i<m; i++)
    {
       cin>> in;
        if(in[0] == 'a' && in[1] == 'd') //add
        {
            cin >> a;
            s = s|(1<<a);
        } 
        else if(in[0] == 'r') // remove
        {
            cin >> a;
            s = s&~(1<<a);
        }
        else if(in[0] == 'c')
           {
             cin >> a;
             if( (s&(1<<a)))
                cout << "1"<<'\n';
            else
                cout << "0"<<'\n';
           }
        else if(in[0] == 't')
        {      
            cin >> a;
            s ^= (1<<a);
        }
        else if(in[0] == 'e')
            s = 0;
        else if(in[0] == 'a' && in[1] == 'l') //all
            s = (1 << 21) - 1;
    }
    return 0;
}