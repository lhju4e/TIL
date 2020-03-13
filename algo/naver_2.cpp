#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
vector<long long> num_list;
void func(int, int, int);
long long solution(int n)
{
  if (n == 1)
    return 2;
  else if (n == 2)
    return 6;
  for (int i = 2; i < 2 * n; i++) // 대략
    func(i, i + 1, n);

  sort(num_list.begin(), num_list.end());
  num_list.erase(unique(num_list.begin(), num_list.end()), num_list.end());

  long long answer = num_list[n-1];
  return answer;
}

void func(int start, int m, int n)
{
  if (start == 2)
    num_list.push_back(2);

  start = start * m;
  num_list.push_back(start);
  if (m > 2*n)
    return;
  func(start, m + 1, n);

  if (start >= powl(10, 12))
    return;
}
int main()
{
  cout << solution(5);
}