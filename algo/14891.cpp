#include <stdio.h>
#include <cstring>
int a[5][8];
int result = 0;
int tmp = 0;
bool check[4] = {
    false,
};
void rotate(int, int);
int main()
{
  int k, num, dir = 0;
  for (int j = 1; j < 5; j++)
    for (int i = 0; i < 8; i++)
      scanf("%1d", &a[j][i]);

  scanf("%d", &k);

  for (int i = 0; i < k; i++)
  {
    memset(check, false, sizeof(check));
    scanf("%d %d", &num, &dir); // 여기서 num은 1-4
    for (int j = 1; j < 4; j++) //맞닿아있는것 체크
    {
      if (a[j][2] != a[j + 1][6]) // 극이 다르면 true
      {
        check[j] = true;
      }
    }
    rotate(num, dir); // 본인방향 돌리기
  tmp = dir;// tmp = 이전 톱니바퀴의 방향
    for (int j = num; j < 4; j++) // 오른쪽으로 맞닿은것들 돌리기(본인제외)
    {       
      if (check[j] == false) //맞닿아있지 않으면 ㄷㅓ이상 안돌림
        break;
      else
      {
        if (tmp == -1)
        {
          rotate(j+1, 1);
          tmp = 1;
        }
        else
        {
          rotate(j+1, -1);
          tmp = -1;
        }
      }
    }
    tmp = dir;
    for (int j = num - 1; j >= 1; j--) // 왼쪽으로 맞닿은것들 돌리기(본인 제외)
    {
      if (check[j] == false) //맞닿아있지 않으면 ㄷㅓ이상 안돌림
        break;
      else
      {
        if (tmp == -1)
        {
          rotate(j, 1);
          tmp = 1;
        }
        else
        {
          rotate(j, -1);
          tmp = -1;
        }
      }
    }
  // for (int j = 0; j < 4; j++)
  //   {for (int x = 0; x < 8; x++)
  //     printf("%d", a[j][x]);
  //     printf("\n");}

  //     printf("===============\n");
    
  }

  if (a[1][0] == 1)
    result += 1;
  if (a[2][0])
    result += 2;
  if (a[3][0])
    result += 4;
  if (a[4][0])
    result += 8;

  printf("%d", result);
  return 0;
}
void rotate(int num, int dir)
{
  int tmp = 0;
  if (dir == 1) // 시계방향
  {
    tmp = a[num][7];
    a[num][7] = a[num][6];
    a[num][6] = a[num][5];
    a[num][5] = a[num][4];
    a[num][4] = a[num][3];
    a[num][3] = a[num][2];
    a[num][2] = a[num][1];
    a[num][1] = a[num][0];
    a[num][0] = tmp;
  }
  else if (dir == -1) // 반시계
  {
    tmp = a[num][0];
    a[num][0] = a[num][1];
    a[num][1] = a[num][2];
    a[num][2] = a[num][3];
    a[num][3] = a[num][4];
    a[num][4] = a[num][5];
    a[num][5] = a[num][6];
    a[num][6] = a[num][7];
    a[num][7] = tmp;
  }

    // for (int j = 1; j < 5; j++)
    // {for (int x = 0; x < 8; x++)
    //   printf("%d", a[j][x]);
    //   printf("\n");}
    //   printf("=====================\n");
}