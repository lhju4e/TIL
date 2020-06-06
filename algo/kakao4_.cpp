#include <iostream>
#include <vector>
#include <map>
#include <queue>
// #include <math.h>
using namespace std;

multimap<string, pair<string, int>> m;

int dfs(string s1, string s2, int cnt)
{
	if(m.count(s1) == 0)
		return -1;
	for(auto iter = m.lower_bound(s1); iter!=m.upper_bound(s1); iter++)
	{
		cnt += iter->second.second;
		if(iter->second.first.compare(s2) == 0)
		{
			return cnt;
		}
		else
		{
			int tmp = dfs(iter->second.first, s2, cnt);
			if(tmp == -1)
				return -1;
			else 
			{
				
			}
			
		}
		
	}
}


int main() {
	int N, M, q;
	cin >> N >> M;
	string tmp1, tmp2;

	for(int i=0; i<M; i++)
	{
		int tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		m.insert(make_pair(tmp1, make_pair(tmp2, tmp3)));
	}
	cin >> q;
	for(int i=0; i<q; i++)
	{
		int min = 0;
		int ans = -1;
		cin >> tmp1 >> tmp2;
		ans = dfs(tmp1, tmp2, 0);
		if()


	}



}