#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> v;
    for(int i=0; i<record.size(); i++)
    {
        vector<string> tmp;
        string a, b, c;
        int index;
        index = record[i].find(" ");
        a = record[i].substr(0, index);
        b = record[i].substr(index+1);
        tmp.push_back(a);
        index = b.find(" ");
        c = b.substr(index+1);
        b = b.substr(0, index);
        tmp.push_back(b);
        tmp.push_back(c);
        v.push_back(tmp);
    }
    for(int i=0; i<v.size(); i++)
    {
        if(!v[i][0].compare("Change"))
        {
            string changename = v[i][1];
            for(int j=0; j<v.size(); j++)
                if(!v[j][1].compare(changename))
                    v[j][2] = v[i][2];
        }
    }
    for(int i=0; i<v.size(); i++)
        cout << v[i][2] << endl;
    return answer;
}

int main()
{
    vector<string>r = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    vector<string> ans;
    ans = solution(r);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i]  << endl;
    return 0;
}