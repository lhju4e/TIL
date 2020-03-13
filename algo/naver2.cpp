#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int solution(vector<string> &A) {
    // write your code in C++14 (g++ 6.2.0)
    do{
      for(int i=0; i<A.size(); i++)
      {
        cout << A[i];
      }
      cout << endl;
    }while(next_permutation(A.begin(), A.end()));
}

int main()
{
  vector<string> A = {"co", "dil", "ity"};
  cout << solution(A);
}
