#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<string> words(num);
    for(int i=0; i<num; i++)
        cin >> words[i];
    

    return 0;
}