#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    vector<int> tmp;
    bool check = false;
    for(int i=heights.size()-1; i>=0; i--)
    {
        check = false;
        for(int j = i-1; j>=0; j--)
        {
            if(heights[j] > heights[i])
            {
                tmp.push_back(j+1);
                check = true;
                break;
            }
        }
        if(!check)
            tmp.push_back(0);

    }
    cout << tmp.size() << endl;
    for(int i=tmp.size()-1; i>=0; i--)
        answer.push_back(tmp[i]);

    return answer;
}

int main()
{
    vector<int> ans = {6, 9, 5, 7, 4};
    vector<int> ret;
    ret = solution(ans);
    for(int i=0; i<ret.size(); i++)
        cout << ret[i] << " ";
    return 0;
}