#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
  int MAX = 100001;
  int n, k = 0;
  int x = 0;
  int cnt[100001] = {0};
  scanf("%d %d", &n, &k);
  queue<int> q;
  q.push(n);
  cnt[n] = 1;

  while (!q.empty())
  {
    x = q.front();
    q.pop();
    //printf(" %d ", x);
    if (x == k)
    {
      printf("%d", cnt[x]-1);
      return 0;
    }
    if (x - 1 >= 0)
      if (cnt[x - 1] == 0)
      {
        q.push(x - 1);
        cnt[x - 1] = cnt[x] + 1;
      }
    if (x + 1 < MAX)
      if (cnt[x + 1] == 0)
      {
        q.push(x + 1);
        cnt[x + 1] = cnt[x] + 1;
      }
    if (2 * x < MAX)
      if (cnt[2 * x] == 0)
      {
        q.push(2 * x);
        cnt[2 * x] = cnt[x];
      }
  }
  return 0;
}