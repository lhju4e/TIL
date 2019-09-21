#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

bool check[1001];
vector<int> a[1001];

void dfs(int);
void bfs(int);

int main()
{
  int n = 0;
  int m = 0;
  int start = 0;
  int v, u;
  scanf("%d %d %d", &n, &m, &start);
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d", &v, &u);
    a[v].push_back(u);
    a[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    sort(a[i].begin(), a[i].end());
  dfs(start);
  printf("\n");
  bfs(start);
  return 0;
}

void dfs(int start)
{
  int next;
  check[start] = true;
  printf("%d ", start);
  for (int i = 0; i < a[start].size(); i++)
  {
    next = a[start][i];
    if (check[next] == false)
      dfs(next);
  }
}

void bfs(int start)
{
  int next;
  memset(check, false, sizeof(check));
  queue<int> q;
  q.push(start);
  check[start] = true;
  while (!q.empty())
  {
    next = q.front();
    printf("%d ", next);
    for (int i = 0; i < a[next].size(); i++)
    {
      if (check[a[next][i]] == false)
        {
          q.push(a[next][i]);
          check[a[next][i]] = true;
        }
    }
    q.pop();
  }
}