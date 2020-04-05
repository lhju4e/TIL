#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string inputString)
{
    int answer = 0;
    int check[4] = {0, 0, 0, 0};
    int close[4] = {0, 0, 0, 0};
    for (int i = 0; i < inputString.size(); i++)
    {
        if (inputString[i] == '(')
        {
            check[0] += 1;
            answer += 1;
        }
        else if (inputString[i] == '{')
        {
            check[1] += 1;
            answer += 1;
        }
        else if (inputString[i] == '[')
        {
            check[2] += 1;
            answer += 1;
        }
        else if (inputString[i] == '<')
        {
            check[3] += 1;
            answer += 1;
        }

        if (inputString[i] == ')')
        {
            close[0] += 1;
            check[0] -= 1;
        }
        else if (inputString[i] == '}')
        {
            close[1] += 1;
            check[1] -= 1;
        }
        else if (inputString[i] == ']')
        {
            close[2] += 1;
            check[2] -= 1;
        }
        else if (inputString[i] == '>')
        {
            close[3] += 1;
            check[3] -= 1;
        }
        for (int j = 0; j < 4; j++) // 순서
        {
            if (check[j] < 0)
            {
                return -1;
            }
        }
    }
    for (int i = 0; i < 4; i++) // 짝
    {
        if (check[i])
            answer = -1;
        break;
    }
    return answer;
}

int main()
{
    string a = ">_<";
    cout << solution(a);
    return 0;
}