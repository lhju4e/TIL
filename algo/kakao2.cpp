#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<string> parse;
    vector<string> copy;
    int idx = 0;
    for(int i=0; i<expression.length(); i++)
    {
        if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-')
        {
            
            parse.push_back(expression.substr(idx, i - idx));
            parse.push_back(expression.substr(i, 1));
            idx = i + 1;
        }
    }
    parse.push_back(expression.substr(idx, expression.length() - idx));

    vector<char> order = {'*', '+', '-'};

    do
    {
        copy.clear();
        for(int i=0; i<parse.size(); i++)
            {
                copy.push_back(parse[i]);
            }
        
        for(int i=0; i<order.size(); i++)
        {
             long long tmp = 0; // 잠시 담을..... 답
            for(int j=0; j<copy.size(); j++)
                if(copy[j][0] == order[i])
                {
                    // cout << copy[j][0] << " " << order[i] << endl;
                    // cout << "j " << j << endl;
                    int idx1 = j -1;
                    int idx2 = j +1;
                    for(int k=j-1; k>=0; k--)
                    {
                        if(copy[k].compare("!") != 0)
                            {idx1 = k;
                            break;}
                    }
                    for(int k = j+1; k<copy.size(); k++)
                    {
                        if(copy[k].compare("!")!=0)
                            {idx2 = k;
                            break;}
                    }
                    // cout << "idx1 " << idx1 << " idx2 " << idx2 << endl;
                    // cout << copy[idx1] << " " << copy[idx2] << endl;

                    long long a = stoll(copy[idx1]);
                    long long b = stoll(copy[idx2]);
                    if(order[i] == '-')
                        tmp = a - b;
                    else if(order[i] == '+')
                        tmp = a + b;
                    else if(order[i] == '*')
                        tmp = a * b;
                    // cout << "tmp " << tmp << endl;
                    copy[j] = to_string(tmp);
                    copy[idx1] = "!";
                    copy[idx2] = "!";
                }
        }

        for(int i=0; i<copy.size(); i++)
            if(copy[i].compare("!") !=0)
            {
                long long tmp = stoll(copy[i]);
                tmp = abs(tmp);
                // cout << "tmp " << tmp << endl;
                if(tmp > answer)
                    answer = tmp;
            }
        // for(int i=0; i<order.size(); i++)
        //     cout << order[i] << " " ;
        // cout << endl;

    } while (next_permutation(order.begin(), order.end()));
    
    return answer;
}


int main()
{
    string a = "50*6-3*2";
    cout << solution(a);
    return 0;
}