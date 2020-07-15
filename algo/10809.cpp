#include <iostream>
#include <string.h>

using namespace std;

int out[26];

int main()
{
    memset(out, -1, sizeof(out));
    string str1;
    cin >> str1;
    for(int i=0; i<str1.length(); i++)
    {
        if(out[str1[i] - 'a'] == -1)
            out[str1[i] - 'a'] = i;
    }
    for(int i=0; i<26; i++)
    {
        cout << out[i] << " ";
    }
}