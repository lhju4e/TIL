#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long dp[81];
long long solution(int N) {
    long long answer = 0;
    dp[1] = 2;
    dp[2] = 3;
    for(int i=3; i<=N; i++)
        dp[i] = dp[i-1] + dp[i-2];
    answer = dp[N]*2;
    return answer;
}

int main()
{
    cout << solution(5);
    return 0;
}