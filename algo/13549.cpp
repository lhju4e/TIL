#include <stdio.h>
#include <deque>
using namespace std;

  int cnt[1000001] = {0,};
  bool check[1000001] = {false};
  int MAX = 1000001;
int main()
{

  int n, k = 0;
  int x = 0;

  scanf("%d %d", &n, &k);
  deque<int> q;
  q.push_back(n);
  cnt[n] = 0;
  check[n] = true;

  while (!q.empty())
  {
    x = q.front();
    q.pop_front();
    //printf(" %d ", x);
    // if (x == k)
    // {
    //   printf("%d\n", cnt[x]);
    //   return 0;
    // }
    if (x - 1 >= 0)
  {    if (check[x - 1] == false)
      {
        q.push_back(x - 1);
        cnt[x - 1] = cnt[x] + 1;
        check[x-1] = true;
      }}
    if (x + 1 < MAX)
  {    if (check[x + 1] == false)
      {
        q.push_back(x + 1);
        check[x+1] = true;
        cnt[x + 1] = cnt[x] + 1;
      }}
    if (2 * x < MAX)
   {   if (check[2 * x] == false)
      {
        q.push_front(2 * x);
        cnt[2 * x] = cnt[x];
        check[2*x] = true;
      }}
  }
  printf("%d", cnt[k]);
  return 0;
}