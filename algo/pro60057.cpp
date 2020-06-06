#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.size();
    int len = s.size();
    for(int i=1; i<=s.size(); i++)
    {
        string s_out = "";
            string tmp = s.substr(0, i);
            int tmp_cnt = 0;
            for(int k = 1; k*i < s.size(); k++)
            {
                string tmp2 = s.substr(k*i, i);
                if(tmp == tmp2)
                {
                    tmp_cnt++;
                }
                else
                {
                    if(tmp_cnt != 0)
                        s_out.append(to_string(tmp_cnt+1));
                    s_out.append(tmp);
                    tmp_cnt = 0;  
                }
                tmp = tmp2;
            }
            if(tmp_cnt != 0)
                s_out.append(to_string(tmp_cnt+1));
            s_out.append(tmp);
            
        // cout << "i " << i << " " << s_out << endl;
        if(answer > s_out.size())
            answer = s_out.size();
    }
    return answer;
}

int main()
{
    string s = "aabbaccc";
    cout << solution(s);
    return 0;
}