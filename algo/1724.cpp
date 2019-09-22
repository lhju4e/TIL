#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;
vector<int> a[1001];
bool check[1001];
void bfs(int);
int cnt=0;

int main()
{
  int n, m;
  int u, v;
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++)
  {
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for(int i=1; i<=n; i++)
  {
    if(!check[i])
    {
      bfs(i);
      cnt++;
    }
  }
  printf("%d", cnt);
  return 0;
}
void bfs(int node)
{
  queue<int> q;
  int next;
  check[node] = true;
  q.push(node);
  while(!q.empty())
  {
    next = q.front();
    q.pop();
    for(int i=0; i<a[next].size(); i++)
    {
      if(check[a[next][i]] == false)
      {q.push(a[next][i]);
      check[a[next][i]] = true;}
    }
  }
}