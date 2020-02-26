#include <iostream>
using namespace std;
void go(int, int); // 재귀적으로 호출하는 함수. 매개변수는 몇 번째 움직임인지 카운트와 방향.
void MOVE(int); // 숫자 사이에 빈 공간을 없애는 함수. 매개변수는 방향.
int MAX = 0;
int cnt = 0;
int n;
int MAP[20][20]; // 전역적으로 사용하는 보드판.
int main()
{
    int COPY[20][20]; // 보드판 배열 복사해서 사용.
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
            COPY[i][j] = MAP[i][j];
            if (MAX < MAP[i][j])
                MAX = MAP[i][j];
        }
    for (int k = 0; k < 4; k++)
    {
        MOVE(k);
        go(0, k);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                MAP[i][j] = COPY[i][j];
    }
    cout << MAX;
    return 0;
}

void MOVE(int b) // 0 4 0 4 0 인 경우, 왼쪽으로 밀면  4 4 0 0 0 으로 이동시킴.
{
    if (b == 0) // 위로 숫자들을 밀음. 위쪽부터 검사를 해서
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                if (!MAP[j][i]) // 만약 이전 숫자가 0인데
                    for (int k = j + 1; k < n; k++)
                        if (MAP[k][i]) // 이후에 0이 아닌 숫자가 있다면
                        {
                            MAP[j][i] = MAP[k][i]; // 자리를 바꿔줌.
                            MAP[k][i] = 0;
                            break;
                        }
    if (b == 1) // 오른쪽
    {
        for (int i = 0; i < n; i++)
            for (int j = n - 1; j > 0; j--)
                if (!MAP[i][j])
                    for (int k = j - 1; k >= 0; k--)
                        if (MAP[i][k])
                        {
                            MAP[i][j] = MAP[i][k];
                            MAP[i][k] = 0;
                            break;
                        }
    }
    if (b == 2) // 아래
    {
        for (int i = 0; i < n; i++)
            for (int j = n - 1; j > 0; j--)
                if (!MAP[j][i])
                    for (int k = j - 1; k >= 0; k--)
                        if (MAP[k][i])
                        {
                            MAP[j][i] = MAP[k][i];
                            MAP[k][i] = 0;
                            break;
                        }
    }
    if(b == 3) // 왼쪽
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                if (!MAP[i][j])
                    for (int k = j + 1; k < n; k++)
                        if (MAP[i][k])
                        {
                            MAP[i][j] = MAP[i][k];
                            MAP[i][k] = 0;
                            break;
                        }
    }
}

void go(int a, int b) // 숫자들을 합쳐줌.
{   
    int COPY[20][20];
    // cout << "========== " << a << " ======" <<  endl;

    if (a == 5)
        return;
    MOVE(b);
    if (b == 0) // 위로 밀기
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                if (MAP[j][i] == MAP[j + 1][i]) // 같은 숫자가 있다면
                {
                    MAP[j][i] = MAP[j][i] * 2; // 합침
                    if (cnt < MAP[j][i]) // 합친 숫자 중 현재 계산한 값보다 큰 값이 있다면
                        cnt = MAP[j][i]; // 그 값을 넣어줌.
                    MAP[j + 1][i] = 0;
                }

    if (b == 1) // 오른쪽으로 밀기
        for (int i = 0; i < n; i++)
            for (int j = n - 1; j > 0; j--)
                if (MAP[i][j] == MAP[i][j - 1])
                {
                    MAP[i][j] = MAP[i][j] * 2;
                    if (cnt < MAP[i][j])
                        cnt = MAP[i][j];
                    MAP[i][j - 1] = 0;
                }

    if (b == 2) // 아래로 밀기
        for (int i = 0; i < n; i++)
            for (int j = n - 1; j > 0; j--)
                if (MAP[j][i] == MAP[j - 1][i])
                {
                    MAP[j][i] = MAP[j][i] * 2;
                    if (cnt < MAP[j][i])
                        cnt = MAP[j][i];
                    MAP[j - 1][i] = 0;
                }
    if (b == 3) // 왼쪽으로 밀기
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                if (MAP[i][j] == MAP[i][j + 1])
                {
                    MAP[i][j] = MAP[i][j] * 2;
                    if (cnt < MAP[i][j])
                        cnt = MAP[i][j];
                    MAP[i][j + 1] = 0;
                }
    MOVE(b);            
    if (MAX < cnt)
        MAX = cnt;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << MAP[i][j] << " ";
    //     cout << endl;
    // }

    for (int k = 0; k < 4; k++)
    { 
                    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            COPY[i][j] = MAP[i][j];   
        go(a + 1, k);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                MAP[i][j] = COPY[i][j];
    }
}