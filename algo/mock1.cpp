#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> bucket;
    int answer = 0;
    for(int k=0; k<moves.size(); k++)
    {
        int crain = moves[k] - 1;
        for(int i=0; i<board.size(); i++)
        {
            if(board[i][crain])
            {
                bucket.push_back(board[i][crain]);
                board[i][crain] = 0;
                break;
            }
        }
    }
    int pre = 0;
    for (int i = 1; i < bucket.size(); i++)
    {
        cout << "pre " << pre << endl;
        for(int j=0; j<bucket.size(); j++)
            cout << bucket[j] << " ";
        cout << endl;
        cout << bucket[i] << endl;
        if (!bucket[i])
            continue;
        if (pre>=0 && bucket[pre] == bucket[i])
        {
            answer += 2;
            bucket[i] = 0;
            bucket[pre] = 0;
            while(pre>=0 && !bucket[pre])
                pre = pre - 1;
        }
        else
            pre = i;
    }
    return answer;
}


int main()
{
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,3,0,3},{0,4,5,0,1},{4,2,4,4,2},{1,5,1,3,1}};
    // vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3}};

    vector<int> moves = {1,5,3,5,1,2};
    cout <<  "sol " << solution(board, moves) ;
}