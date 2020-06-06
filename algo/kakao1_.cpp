#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    bool check[5];
    for(int i=0; i<5; i++)
        check[i] = false;
    // 0 : 영소 1 : 영대, 2 : 숫자 3 : 특문 4 : 길이
    if(s.size() >= 10)
        check[4] = true;
    for(int i=0; i<s.size(); i++)
    {
        char a = s.at(i);
        if(a >= 'a' && a <= 'z')
            check[0] = true;
        else if(a >= 'A' && a <= 'Z')
            check[1] = true;
        else if(a >= '0' && a <= '9')
            check[2] = true;
        else
            check[3] = true;
        if(check[0] && check[1] && check[2] && check[3] && check[4])
                break;
    }
    int cnt = 0;
    for(int i=0; i<5; i++)
    {
        if(check[i])
            cnt++;
    }
    cout << "LEVEL" << cnt;
	return 0;
}