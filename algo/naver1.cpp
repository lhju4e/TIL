#include <string>
#include <iostream>
using namespace std;

string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int len = S.length();
    cout << len << endl;
    for(int i=0; i<len/2; i++)
    {
      if(S.at(i) != S.at(len-i-1))
      {
        if(S.at(i) != '?' && S.at(len-i-1) != '?')
        {
          return "NO";
        }
        if(S.at(i) == '?')
          S.at(i) = S.at(len-i-1);
        else if(S.at(len-i-1) == '?')
          S.at(len-i-1) = S.at(i);
      }
      else if(S.at(i) == '?')
      {
        S.at(i) = 'a';
        S.at(len-i-1) = 'a';
      }
    }
    return S;
}

int main()
{
  string S = "?ab??a";
  cout << solution(S);
  return 0;
}