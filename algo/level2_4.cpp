#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    int i=0; int j = people.size()-1;
    while(i<j)
    {
        if(limit < people[i] + people[j])
            {
                j--;
            answer++; // 같이 못타는 사람들.
            }
        else
        {
            answer++; // 같이타는사람들.
            i++; j--;
        }
        
    } 
    if(i == j) // 두명씩 짝지었을때 홀수가되면
        answer++;
    return answer;
}

int main()
{
    vector<int> people = {70, 80, 50};
    int limit = 100;
    cout << solution(people, limit);
    return 0;
}