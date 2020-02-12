#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;
char com[10];
vector<int> maxnu, minnu;
bool check(vector<int> &v, int k)
{
    for(int i=0; i<k; i++)
    {
      if(com[i] == '<')
        if(v[i] > v[i+1])
          return false;
      if(com[i] == '>')
        if(v[i] < v[i+1])
          return false;
    }
    return true;
}

int main()
{
  int k;
  scanf("%d", &k);
  for(int i=0; i<k; i++)
    cin >> com[i];
  for(int i=0; i<10; i++)
    minnu.push_back(i);
  for(int i=9; i>=0; i--)
    maxnu.push_back(i);
  do{
    if(check(minnu, k))
      break;
  }while(next_permutation(minnu.begin(), minnu.end()));
    do{
    if(check(maxnu, k))
      break;
  }while(prev_permutation(maxnu.begin(), maxnu.end()));

  for(int i=0; i<=k; i++)
    printf("%d", maxnu[i]);
  printf("\n");
  for(int i=0; i<=k; i++)
    printf("%d", minnu[i]);
  return 0;
}