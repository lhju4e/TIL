#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    // bool right[4][3];
    // bool left[4][3];
    // for(int i=0; i<4; i++)
    //     for(int j=0; j<3; j++)
    //     {
    //         right[i][j] = false;
    //         left[i][j] = false;
    //     }
    // right[3][2] = true;
    // left[3][0] = true;
    pair<int, int> left;
    pair<int, int> right;
    left = make_pair(3, 0);
    right = make_pair(3, 2);

    for(int i=0; i<numbers.size(); i++)
    {
        int num;
        num = numbers[i];

        if(num == 0)
        {
            int x = 3;
            int y = 1;
            int left_dist = abs(x - left.first) + abs(y - left.second);
            int right_dist = abs(x - right.first) + abs( y - right.second);
            if(left_dist > right_dist) // 오른손이 더 가깝다면
            {
                answer += "R";
                right = make_pair(x, y);
            }   
            else if(left_dist < right_dist) // 왼손이 더 가깝다면
            {
                answer += "L";
                left = make_pair(x, y);
            }
            else
            {
                if(hand.compare("right") == 0)
                {
                    answer+= "R";
                    right = make_pair(x, y);
                }
                else
                {
                    answer += "L";
                    left = make_pair(x, y);
                }
            }
            continue;
        }

        if(num%3 == 1) // 왼손 사용
        {
            answer += "L";
            left = make_pair(num/3, 0);
            // left[num/3][0] = true;

        }
        else if(num%3 == 0) // 오른손 사용
        {
            answer += "R";
            right = make_pair((num/3)-1, 2);
        }
        else // 양손 사용
        {
            int x = num/3;
            int y = num%3 -1;
            int left_dist = abs(x - left.first) + abs(y - left.second);
            int right_dist = abs(x - right.first) + abs( y - right.second);
            // cout << "left_dist : " << left_dist << 
            if(left_dist > right_dist) // 오른손이 더 가깝다면
            {
                answer += "R";
                right = make_pair((num/3), num%3 -1);
            }   
            else if(left_dist < right_dist) // 왼손이 더 가깝다면
            {
                answer += "L";
                left = make_pair((num/3), num%3 -1);
            }
            else
            {
                if(hand.compare("right") == 0)
                {
                    answer+= "R";
                    right = make_pair((num/3), num%3 -1);
                }
                else
                {
                    answer += "L";
                    left = make_pair((num/3), num%3 -1);
                }
            }
                  
        }
        // cout << num << " " << "left " << left.first << " " << left.second << " right " << right.first << " " << right.second << endl;
    }
    return answer;
}

int main()
{
    // vector<int> nums = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    // string ans = solution(nums, "right");
    // vector<int> nums = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    // string ans = solution(nums, "left");
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    string ans = solution(nums, "right");
    for(int i=0; i<ans.length(); i++)
        cout << ans[i];
    return 0;
}