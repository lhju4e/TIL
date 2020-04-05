#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string answer_sheet, vector<string> sheets) {
        int answer = 0;

    for(int i=0; i<sheets.size(); i++)
    {
        for(int j=i+1; j<sheets.size(); j++)
        {
            int cnt = 0;
            int index = -1; // 연속인지 알려주는.
            int chain = 0;
            int chainmax = 0;
            for(int k=0; k<sheets[i].size(); k++)
            {
                if(sheets[i][k] != answer_sheet[k] && sheets[i][k] == sheets[j][k])
                {
                    cnt++;
                    if(index != -1 && index == k-1)
                        chain++; // 이전이랑 이어지면 연속.
                    if(index != k-1)
                        chain = 0;
                    index = k;
                    if(chainmax < chain)
                        chainmax = chain;
                }
            }
            if(cnt) // 연속이 0부터 시작하니까 1씩 더해주ㅓ야함.
                chainmax += 1;
            // cout << "cnt " << cnt << " chainmax " << chainmax << endl;
            int tmp = cnt + chainmax*chainmax;
            // cout << tmp << endl;
            if(answer < tmp)
                answer = tmp;
        }
    }
    return answer;
}

int main()
{
    string ans = "4132315142";
    vector<string> sheet = {"3241523133","4121314445","3243523133","4433325251","2412313253"};
    cout << solution(ans, sheet);
    return 0;
}