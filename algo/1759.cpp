#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int go(int, vector<char>&, string, int);
int main()
{
	int l, c; //c개의 문자 중 l개를 뽑아서 password로
    string tmp = "";
	cin>>l>>c;
    vector<char> alpha(c);
	for (int i = 0; i < c; i++)
		cin >> alpha[i];
	sort(alpha.begin(), alpha.end());
	go(l, alpha, tmp, 0);
	return 0;
}


int go(int n, vector<char>& alpha, string pass, int index)
{
    if (index > alpha.size())
		return 0; //찾지 못한 경우. 멈춰야 함.
	if (pass.length() == n)//찾은 경우
	{
		int tmp = 0;
		for (int i = 0; i < n; i++) // 모음이 한 개 이상이고 자음이 두 개 이상인지
		{
			if (pass[i] == 'a' || pass[i] == 'i' || pass[i] == 'o' || pass[i] == 'e' || pass[i] == 'u')
				tmp++;
		}
        if((tmp>=1)&&(n-tmp)>=2)
        {
            cout<<pass;
            cout<<'\n';
            return 0;
        }
    }
    go(n, alpha, pass+alpha[index], index+1);
    go(n, alpha, pass, index+1);
}