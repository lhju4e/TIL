#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for(int i=0; i<participant.size(); i++)
      m[participant[i]]++;
    for(int i=0; i<completion.size(); i++)
      m[completion[i]]--;

    for(auto iter = m.begin(); iter!=m.end(); iter++)
    {
      if(iter->second != 0)
        return iter->first;
    }
}
int main()
{
  vector<string> a;
  a.push_back("mislav");
  a.push_back("stanko");
  a.push_back("mislav");
  a.push_back("ana");

  vector<string> b;
  b.push_back("stanko");
  b.push_back("ana");
  b.push_back("mislav");

  cout << solution(a,b);
}