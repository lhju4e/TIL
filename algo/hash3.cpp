#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> total;
    map<int, string, greater<int>> total2;
    for(int i=0; i<genres.size(); i++)   
      total[genres[i]] += plays[i];

    for(auto iter=total.begin(); iter!=total.end(); iter++)
      total2[iter->second] = iter->first;

    // pair<int, int> tmp[10010];
    map<string, pair<int, int>> tmp;
    for(auto iter=total2.begin(); iter!=total2.end(); iter++)
    {
      string gen = iter->second;
      tmp[gen] = make_pair(-1, -1);
      for(int i=0; i<genres.size(); i++)
      {
        if(gen.compare(genres[i]) == 0)
        {
          if(plays[tmp[gen].first] <plays[i])
          {
            tmp[gen].second = tmp[gen].first;
            tmp[gen].first = i;
          }
          else if(plays[tmp[gen].second] < plays[i])
            tmp[gen].second = i;
        }
      }
    if(tmp[gen].first != -1)
      answer.push_back(tmp[gen].first);
    if(tmp[gen].second != -1)
      answer.push_back(tmp[gen].second);
    }
    return answer;
}

int main()
{
  vector<string> geners;
  geners.push_back("classic");
  geners.push_back("pop");
  geners.push_back("classic");
  geners.push_back("classic");
  geners.push_back("pop");

  vector<int> plays;
  plays.push_back(500);
  plays.push_back(600);
  plays.push_back(150);
  plays.push_back(800);
  plays.push_back(2500);
  solution(geners, plays);
  // cout << solution(geners, plays);
}