#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> solution(vector<string> record)
{
  vector<string> save;
  vector<string> answer;

  for(int i=0; i<record.size(); i++)
  {
    if(record[i].find("RECEIVE") != string::npos) // RECEIVE명령어
    {
        record[i].replace(0, 8, "");
        save.push_back(record[i]);
    }
    else if(record[i].find("SAVE") != string::npos) // SAVE명령어
    {
      for(int i=0; i<save.size(); i++)
        answer.push_back(save[i]);
    }
    else // DELETE
    {
      if(!save.empty())
        save.pop_back();
    }
  }
  return answer;
}

int main()
{
  vector<string> answer;
  vector<string> record ={ "RECEIVE abcd@naver.com", 
  "RECEIVE zzkn@naver.com", "DELETE", "RECEIVE qwerty@naver.com", 
  "SAVE", "RECEIVE QwerTY@naver.com"};
  answer = solution(record);
  for(int i=0; i<answer.size(); i++)
   cout << answer[i];
  return 0;
}