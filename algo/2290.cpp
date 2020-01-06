#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
void monitor_1(char);
void monitor_2(char);
void monitor_3(char);
void monitor_4(char);
void monitor_5(char);
using namespace std;
int s = 0;
string n;
int main()
{
  scanf("%d", &s);
  cin >> n;

  for (int i = 0; i < n.size(); i++)
    monitor_1(n.at(i));
  for (int i = 0; i < n.size(); i++)
    monitor_2(n.at(i));
  for (int i = 0; i < n.size(); i++)
    monitor_3(n.at(i));
  for (int i = 0; i < n.size(); i++)
    monitor_4(n.at(i));
  for (int i = 0; i < n.size(); i++)
    monitor_5(n.at(i));
  return 0;
}

void monitor_1(char n)
{
  char digit[100][100] = {
      NULL,
  };
  bool check[7] = {true};
  memset(check, true, sizeof(check));
  if (n == '1')
    check[0] = false;
  else if (n == '4')
    check[0] = false;

  if (check[0] == true)
    for (int i = 2; i <= 1 + s; i++)
      digit[1][i] = '-';

    for (int j = 1; j <= s + 2; j++)
      printf("%c", digit[0][j]);
}

void monitor_2(char n)
{
  char digit[100][100] = {
      NULL,
  };
  bool check[7] = {true};
  memset(check, true, sizeof(check));

  if (n == '1')
    check[1] = false;
  else if (n == '2')
    check[1] = false;
  else if (n == '3')
    check[1] = false;
  else if (n == '5')
    check[2] = false;
  else if (n == '6')
    check[2] = false;
  else if (n == '7')
    check[1] = false;

  if (check[1] == true)
    for (int i = 2; i <= s + 1; i++)
      digit[i][1] = '|';
  if (check[2])
    for (int i = 2; i <= s + 1; i++)
      digit[i][s + 2] = '|';

  for (int i = 1; i <= 2 * s + 3; i++)
  {
    for (int j = 1; j <= s + 2; j++)
      printf("%c", digit[i][j]);
    printf("\n");
  }
}

void monitor(char n)
{
  char digit[100][100] = {
      NULL,
  };
  bool check[7] = {true};
  memset(check, true, sizeof(check));
  if (n == '0')
    check[3] = false;
  else if (n == '1')
  {
    check[0] = false;
    check[1] = false;
    check[3] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '2')
  {
    check[1] = false;
    check[5] = false;
  }
  else if (n == '3')
  {
    check[1] = false;
    check[4] = false;
  }
  else if (n == '4')
  {
    check[0] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '5')
  {
    check[2] = false;
    check[4] = false;
  }
  else if (n == '6')
    check[2] = false;
  else if (n == '7')
  {
    check[1] = false;
    check[3] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '9')
    check[4] = false;

  if (check[0] == true)
    for (int i = 2; i <= 1 + s; i++)
      digit[1][i] = '-';
  if (check[1] == true)
    for (int i = 2; i <= s + 1; i++)
      digit[i][1] = '|';
  if (check[2])
    for (int i = 2; i <= s + 1; i++)
      digit[i][s + 2] = '|';
  if (check[3])
    for (int i = 2; i <= 1 + s; i++)
      digit[s + 2][i] = '-';
  if (check[4])
    for (int i = s + 3; i <= 2 * s + 2; i++)
      digit[i][1] = '|';
  if (check[5])
    for (int i = s + 3; i <= 2 * s + 2; i++)
      digit[i][s + 2] = '|';
  if (check[6] == true)
    for (int i = 2; i <= 1 + s; i++)
      digit[s * 2 + 3][i] = '-';

  for (int i = 1; i <= 2 * s + 3; i++)
  {
    for (int j = 1; j <= s + 2; j++)
      printf("%c", digit[i][j]);
    printf("\n");
  }
}

void monitor(char n)
{
  char digit[100][100] = {
      NULL,
  };
  bool check[7] = {true};
  memset(check, true, sizeof(check));
  if (n == '0')
    check[3] = false;
  else if (n == '1')
  {
    check[0] = false;
    check[1] = false;
    check[3] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '2')
  {
    check[1] = false;
    check[5] = false;
  }
  else if (n == '3')
  {
    check[1] = false;
    check[4] = false;
  }
  else if (n == '4')
  {
    check[0] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '5')
  {
    check[2] = false;
    check[4] = false;
  }
  else if (n == '6')
    check[2] = false;
  else if (n == '7')
  {
    check[1] = false;
    check[3] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '9')
    check[4] = false;

  if (check[0] == true)
    for (int i = 2; i <= 1 + s; i++)
      digit[1][i] = '-';
  if (check[1] == true)
    for (int i = 2; i <= s + 1; i++)
      digit[i][1] = '|';
  if (check[2])
    for (int i = 2; i <= s + 1; i++)
      digit[i][s + 2] = '|';
  if (check[3])
    for (int i = 2; i <= 1 + s; i++)
      digit[s + 2][i] = '-';
  if (check[4])
    for (int i = s + 3; i <= 2 * s + 2; i++)
      digit[i][1] = '|';
  if (check[5])
    for (int i = s + 3; i <= 2 * s + 2; i++)
      digit[i][s + 2] = '|';
  if (check[6] == true)
    for (int i = 2; i <= 1 + s; i++)
      digit[s * 2 + 3][i] = '-';

  for (int i = 1; i <= 2 * s + 3; i++)
  {
    for (int j = 1; j <= s + 2; j++)
      printf("%c", digit[i][j]);
    printf("\n");
  }
}

void monitor(char n)
{
  char digit[100][100] = {
      NULL,
  };
  bool check[7] = {true};
  memset(check, true, sizeof(check));
  if (n == '0')
    check[3] = false;
  else if (n == '1')
  {
    check[0] = false;
    check[1] = false;
    check[3] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '2')
  {
    check[1] = false;
    check[5] = false;
  }
  else if (n == '3')
  {
    check[1] = false;
    check[4] = false;
  }
  else if (n == '4')
  {
    check[0] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '5')
  {
    check[2] = false;
    check[4] = false;
  }
  else if (n == '6')
    check[2] = false;
  else if (n == '7')
  {
    check[1] = false;
    check[3] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '9')
    check[4] = false;

  if (check[0] == true)
    for (int i = 2; i <= 1 + s; i++)
      digit[1][i] = '-';
  if (check[1] == true)
    for (int i = 2; i <= s + 1; i++)
      digit[i][1] = '|';
  if (check[2])
    for (int i = 2; i <= s + 1; i++)
      digit[i][s + 2] = '|';
  if (check[3])
    for (int i = 2; i <= 1 + s; i++)
      digit[s + 2][i] = '-';
  if (check[4])
    for (int i = s + 3; i <= 2 * s + 2; i++)
      digit[i][1] = '|';
  if (check[5])
    for (int i = s + 3; i <= 2 * s + 2; i++)
      digit[i][s + 2] = '|';
  if (check[6] == true)
    for (int i = 2; i <= 1 + s; i++)
      digit[s * 2 + 3][i] = '-';

  for (int i = 1; i <= 2 * s + 3; i++)
  {
    for (int j = 1; j <= s + 2; j++)
      printf("%c", digit[i][j]);
    printf("\n");
  }
}
void monitor(char n)
{
  char digit[100][100] = {
      NULL,
  };
  bool check[7] = {true};
  memset(check, true, sizeof(check));
  if (n == '0')
    check[3] = false;
  else if (n == '1')
  {
    check[0] = false;
    check[1] = false;
    check[3] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '2')
  {
    check[1] = false;
    check[5] = false;
  }
  else if (n == '3')
  {
    check[1] = false;
    check[4] = false;
  }
  else if (n == '4')
  {
    check[0] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '5')
  {
    check[2] = false;
    check[4] = false;
  }
  else if (n == '6')
    check[2] = false;
  else if (n == '7')
  {
    check[1] = false;
    check[3] = false;
    check[4] = false;
    check[6] = false;
  }
  else if (n == '9')
    check[4] = false;

  if (check[0] == true)
    for (int i = 2; i <= 1 + s; i++)
      digit[1][i] = '-';
  if (check[1] == true)
    for (int i = 2; i <= s + 1; i++)
      digit[i][1] = '|';
  if (check[2])
    for (int i = 2; i <= s + 1; i++)
      digit[i][s + 2] = '|';
  if (check[3])
    for (int i = 2; i <= 1 + s; i++)
      digit[s + 2][i] = '-';
  if (check[4])
    for (int i = s + 3; i <= 2 * s + 2; i++)
      digit[i][1] = '|';
  if (check[5])
    for (int i = s + 3; i <= 2 * s + 2; i++)
      digit[i][s + 2] = '|';
  if (check[6] == true)
    for (int i = 2; i <= 1 + s; i++)
      digit[s * 2 + 3][i] = '-';

  for (int i = 1; i <= 2 * s + 3; i++)
  {
    for (int j = 1; j <= s + 2; j++)
      printf("%c", digit[i][j]);
    printf("\n");
  }
}