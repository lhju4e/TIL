#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

int group[20001];
vector<int> g[20001];
using namespace std;
bool dfs(int, int);
int main()
{
  int k;
  scanf("%d", &k);
  for (int t = 0; t < k; t++)
  {
    int v, e;
    scanf("%d %d", &v, &e);
        memset(group, 0, sizeof(group));
    for (int i = 1; i <= v; i++)
      g[i].clear();

    for (int i = 0; i < e; i++)
    {
     int a, b;
      scanf("%d %d", &a, &b);
      g[a].push_back(b);
      g[b].push_back(a);
    }
    bool ok = true;
    for (int i = 1; i <= v; i++)
    {
      if (group[i] == 0)
        {if ((dfs(i, 1)) == true)
          ok = true;
        else
          ok = false;}
    }
    if (ok)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

bool dfs(int node, int color)
{
  int next;
  group[node] = color;
  for (int i = 0; i < g[node].size(); i++)
  {
    next = g[node][i];
  //  printf("next : %d color : %d\n", next, color);
    if (!group[next]) // 방문 안했으면
    {
      if (dfs(next, 3 - color) == false)
        return false;
    }
    else //방문했으면
    {
      if ((group[next]) == (group[node])) // 같은그룹인지 체크
      {
//        printf("next color : %d, node color : %d", group[next], group[node]);
        return false;
      }
    }
  }
  return true;
}