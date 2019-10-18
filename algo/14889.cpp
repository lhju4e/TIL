#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int s[20][20];
int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> s[i][j];

  vector<int>num;
  for(int i=0; i<n/2; i++)
    num.push_back(0);
  for(int i=n/2; i<n; i++)
    num.push_back(1);
  sort(num.begin(), num.end());
  int result = 1000;
  vector<int> index_a(n/2);
  vector<int> index_b(n/2);
  int sum_a = 0;
  int sum_b = 0;
  int cnt_a = 0;
  int cnt_b = 0;
  do{ 
    for(int i=0; i<n; i++)
      {
        if(num[i] == 1)
          {
          index_a[cnt_a] = i;
          cnt_a++;
          }
        else
          {
            index_b[cnt_b] = i;
            cnt_b++;
          }
      }
    for(int i=0; i<n/2; i++)
      for(int j=i+1; j<n/2; j++)
        {
          sum_a = sum_a + s[index_a[i]][index_a[j]] + s[index_a[j]][index_a[i]];
          sum_b = sum_b + s[index_b[i]][index_b[j]] + s[index_b[j]][index_b[i]];
        }
    // std::cout << "sum_a "<< sum_a << endl;
    // std::cout << "sum_b "<< sum_b << endl; 
    if(result > abs(sum_a - sum_b))
        result = abs(sum_a - sum_b);
    sum_a = 0;
    sum_b = 0;
    cnt_a = 0;
    cnt_b = 0 ;
  }while(next_permutation(num.begin(), num.end()));
  std::cout << result;
  return 0;
}
