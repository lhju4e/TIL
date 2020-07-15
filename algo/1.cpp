#include <string>
#include <vector>
#include <iostream>
using namespace std;

string func(string compressed) // 괄호 풀어주는 함수
{
    int num = 0;
    int index = 0;

    for (int i = 0; i < compressed.length(); i++)
    {
        if (compressed[i] == '(')
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (compressed[j] >= '0' && compressed[j] <= '9')
                    index = j;
                else
                    break;
            }
            num = stoi(compressed.substr(index, i));
        }
        if (compressed[i] == ')')
        {
            string restore = "";
            restore = compressed.substr(index + 2, i - index - 2);
            for (int i = 1; i < num; i++)
                restore += restore;
            compressed = compressed.replace(index, i - index + 1, restore);
        }
    }
    if(compressed.find("(") == std::string::npos)
        return compressed;
    else
        compressed = func(compressed);

    return compressed;
}

string solution(string compressed)
{
    string answer = "";
    answer = func(compressed);
    return answer;
}

int main()
{
    cout << solution("2(2(hi)2(co))x2(bo)");
    return 0;
}