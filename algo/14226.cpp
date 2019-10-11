#include <stdio.h>
#include <queue>
using namespace std;
int cnt[1001][1001];
int main()
{
  int s = 0;
  int result, dis, tmp = 0;
  queue<pair<int, int>> q; // 화면, 클립보드
  scanf("%d", &s);

  q.push(make_pair(1, 0));
  cnt[1][0] = 1;
  while (!q.empty())
  {
    dis = q.front().first;
    tmp = q.front().second;
    q.pop();
    if (dis == s)
    {
      printf("%d", cnt[dis][tmp] - 1);
      return 0;
    }
    //화면 -> 클립보드
    if (cnt[dis][dis] == 0)
    {
      q.push(make_pair(dis, dis));
      //     printf("push dis tmp %d %d\n", dis, tmp);
      cnt[dis][dis] = cnt[dis][tmp] + 1;
    }
    //클립보드 -> 화면
    if (dis + tmp < 1001)
      if (tmp != 0 && cnt[dis + tmp][tmp] == 0)
      {
        q.push(make_pair(dis + tmp, tmp));
        //         printf("push dis tmp %d %d\n", dis, tmp);
        cnt[dis + tmp][tmp] = cnt[dis][tmp] + 1;
      }
    //화면하나삭제
    if (dis - 1 >= 0)
      if (cnt[dis - 1][tmp] == 0)
      {
        q.push(make_pair(dis - 1, tmp));
        //          printf("push dis tmp %d %d\n", dis, tmp);
        cnt[dis - 1][tmp] = cnt[dis][tmp] + 1;
      }
  }
  return 0;
}