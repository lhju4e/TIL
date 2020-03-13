#include <stdio.h>
#include <iostream>
#include <tuple>

void swap(int code);
int cube[7][10];
void rotate(bool a, int b);

int main()
{
  int t =0, m=0, c=0,p=0;
  scanf("%d", &t);
  for(int i=0; i<t; i++)
  {
    int j=1;
    for(int k=1; k<7; k++)
    {
      for(int l=1; l<10; l++)
      {
        cube[k][l] = j;
        j++;
      }
    }
  //  for(int k=1; k<7; k++)
  //     for(int l=1; l<10; l++)
  //       printf("cube[%d][%d]: %d\n", k, l, cube[k][l]);

    scanf("%d", &m);
    for(int j=0; j<m; j++)
    {
      scanf("%d", &c);
      swap(c);
    }
    scanf("%d", &p);

    printf("#%d", i+1);

      for(int j=1; j<10; j++)
        printf(" %d", cube[p][j]);
      printf("\n");
    
  }
  return 0;
}

void swap(int code)
{
  int tmp[3];
  if(code <4)
  {
    if(code == 1)
      rotate(1, 5);
    if(code == 3)
      rotate(0, 6);
    tmp[0] = cube[2][code];
    tmp[1] = cube[2][code+3];
    tmp[2] = cube[2][code+6];

    cube[2][code] = cube[3][code];
    cube[2][code+3] = cube[3][code+3];
    cube[2][code+6] = cube[3][code+6];

    cube[3][code] = cube[4][code];
    cube[3][code+3] = cube[4][code+3];
    cube[3][code+6] = cube[4][code+6];

    cube[4][code] = cube[1][code];
    cube[4][3+code] = cube[1][code+3];
    cube[4][6+code] = cube[1][code+6];

    cube[1][code] = tmp[0];
    cube[1][code+3] = tmp[1];
    cube[1][code+6] = tmp[2];
  }
  else if(code>=4 && code <=6)
  {
    if(code == 4)
      rotate(0, 5);
    if(code == 6)
      rotate(1, 6);
    code = code - 3;
    tmp[0] = cube[2][code];
    tmp[1] = cube[2][code+3];
    tmp[2] = cube[2][code+6];

    cube[2][code] = cube[1][code];
    cube[2][code+3] = cube[1][code+3];
    cube[2][code+6] = cube[1][code+6];

    cube[1][code] = cube[4][code];
    cube[1][code+3] = cube[4][3+code];
    cube[1][code+6] = cube[4][6+code];

    cube[4][code] = cube[3][code];
    cube[4][3+code] = cube[3][code+3];
    cube[4][6+code] = cube[3][code+6];

    cube[3][code] = tmp[0];
    cube[3][code+3] = tmp[1];
    cube[3][code+6] = tmp[2];
  }
  else if(code >=7 && code <=9)
  {
    if(code == 7)
{      code = 1;
      rotate(0, 1);
}    
else if(code == 8)
     code = 4;
    else
      {code = 7;
      rotate(1, 3);}
    
    tmp[0] = cube[2][code];
    tmp[1] = cube[2][code+1];
    tmp[2] = cube[2][code+2];

    cube[2][code] = cube[6][code];
    cube[2][code+1] = cube[6][code+1];
    cube[2][code+2] = cube[6][code+2];

    cube[6][code] = cube[4][10-code];
    cube[6][code+1] = cube[4][9-code];
    cube[6][code+2] = cube[4][8-code];

    cube[4][10-code] = cube[5][code];
    cube[4][9-code] = cube[5][code+1];
    cube[4][8-code] = cube[5][code+2];

    cube[5][code] = tmp[0];
    cube[5][code+1] = tmp[1];
    cube[5][code+2] = tmp[2];
  }
  else
  {
    if(code == 10)
     { code = 1;
     rotate(1, 1);}
    else if(code == 11)
      code = 4;
    else
     { code = 7;
     rotate(0, 3);}
    
    tmp[0] = cube[2][code];
    tmp[1] = cube[2][code+1];
    tmp[2] = cube[2][code+2];

    cube[2][code] = cube[5][code];
    cube[2][code+1] = cube[5][code+1];
    cube[2][code+2] = cube[5][code+2];

    cube[5][code] = cube[4][10-code];
    cube[5][code+1] = cube[4][9-code];
    cube[5][code+2] = cube[4][8-code];

    cube[4][10-code] = cube[6][code];
    cube[4][9-code] = cube[6][code+1];
    cube[4][8-code] = cube[6][code+2];

    cube[6][code] = tmp[0];
    cube[6][code+1] = tmp[1];
    cube[6][code+2] = tmp[2];
  }
}

void rotate(bool a, int b)
{
  int tmp = 0;
  if(a) // 왼쪽으로회전
  {
    tmp = cube[b][1];
    cube[b][1] = cube[b][3];
    cube[b][3] = cube[b][9];
    cube[b][9] = cube[b][7];
    cube[b][7] = tmp;
    tmp = cube[b][2];
    cube[b][2] = cube[b][6];
    cube[b][6] = cube[b][8];
    cube[b][8] = cube[b][4];
    cube[b][4] = tmp;
  }
  else
  {
    tmp = cube[b][1];
    cube[b][1] = cube[b][7];
    cube[b][7] = cube[b][9];
    cube[b][9] = cube[b][3];
    cube[b][3] = tmp;
    tmp = cube[b][2];
    cube[b][2] = cube[b][4];
    cube[b][4] = cube[b][8];
    cube[b][8] = cube[b][6];
    cube[b][6] = tmp;
  }
  
}