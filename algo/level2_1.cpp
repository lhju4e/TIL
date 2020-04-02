#include <string>
#include <vector>
#include <iostream>

using namespace std;
string go(string);
string solution(string p) {
    string answer = go(p);
    return answer;
}

int main()
{
    string a = "()))((()";
    // string a = ")(";
    // string a = "(()())()";
    cout << "ans " << solution(a);
}

string go(string a)
{
    // cout << "A " <<  a <<endl;
    if(a.empty())
        return "";
    int left = 0;
    int right = 0 ;
    int index = 0;
    bool correct = true;
    for(; index<a.size(); index++)
    {
        if(a.at(index) == '(')
            left++;
        if(a.at(index) == ')')
        {    
            right++;
            if(left<right)
                correct = false;
        }
        if(left && left==right)
           break;
    }
    // cout << "index " << index << endl;
    string u = a.substr(0, index +1);
    // cout << u << endl;
    string v = a.substr(index+1);
    // cout <<"v " <<  v << endl;
    string next = "";
    if(correct)
        {
            // cout << "correct " << endl;
            next = go(v);
        return u + next;
        }
    else
    {
        next = "(" + v + ")";
        u = u.substr(1, u.size()-2);
        for(int i=0; i<u.size(); i++)
            if(u.at(i) == '(')
                u.at(i) = ')';
            else
                u.at(i) = '(';
        return next + u;
    }  
}