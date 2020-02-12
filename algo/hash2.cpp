#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int>m;
    for(int i=0; i<clothes.size(); i++)
      m[clothes[i][1]]++;
    for(auto iter=m.begin(); iter!=m.end(); iter++)
    {
      answer *= (iter->second + 1);
    }
    answer -= 1;
    return answer;
}

int main()
{
  vector<vector<string>> clothes(3);
  clothes[0].push_back("yellow_hat");
  clothes[0].push_back("headgear");
  clothes[1].push_back("blue_sunglasses");
  clothes[1].push_back("eyewear");
  clothes[2].push_back("green_turban");
  clothes[2].push_back("headgear");
  cout <<solution(clothes);
  return 0;
}