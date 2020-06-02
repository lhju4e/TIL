#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string input;
    vector<string> v;
    int cnt = 0;
    int start = 0;
    getline(cin, input);
    for(int end=0; end<input.size(); end++)
    {
        if(input[end] == ' ')
        {
            string tmp = input.substr(start, end-start);
            // cout << "tmp " << tmp << endl;
            if(!tmp.empty())
                v.push_back(tmp);
            start = end+1;
        }
    }
    string tmp = input.substr(start);
    if(!tmp.empty())
        v.push_back(tmp);
    // for(int i=0; i<v.size(); i++)
    //     cout << v[i] << endl;
    cout << v.size();
    return 0;
}