#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int main()
{
  char a[200];
  scanf("%s", a); // 기본 변수형
  while (1)
  {
    char b[200];
    scanf("%s", b); //변수명
    string str2(b);
    string str3;
    if (str2.find(";") != std::string::npos)
    {
      str2.pop_back(); // str2에 ;를 파싱
      while (1)
      {
        char tmp;
        tmp = str2.back();
        if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z')) // 알파벳을 만나면
          break;
        else
        {
          str2.pop_back();
          if (tmp == ']') // 끝이 ]면 하나 더뺌
          {
            str2.pop_back();
            str3 += "[]";
          }
          else
            str3 += tmp;
        }
      }
      printf("%s", a);
      cout << str3;
      cout << " " << str2 << ";" << endl;
      str2.clear();
      str3.clear();
      break;
    }
    else
    {
      str2.pop_back(); // str2에 ,를 파싱함
      while (1)
      {
        char tmp;
        tmp = str2.back();

        if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z')) // 알파벳을 만나면
          break;
        else
        {
          str2.pop_back();
          if (tmp == ']') // 끝이 ]면 하나 더뺌
          {
            str2.pop_back();
            str3 += "[]";
          }
          else
            str3 += tmp;
        }
      }
    }
    printf("%s", a);
    cout << str3;
    cout << " " << str2 << ";" << endl;
    str2.clear();
    str3.clear();
  }
  return 0;
}