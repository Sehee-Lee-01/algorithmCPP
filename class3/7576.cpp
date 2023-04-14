#include <iostream>
using namespace std;
#define MAX N *M + 1

int main()
{
    int M, N;
    cin >> M >> N;

    int map[N][M], unripeCnt = 0, ripeCnt = 0, ripeList[MAX][2];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                unripeCnt++;
            else if (map[i][j] == 1)
            {
                ripeList[++ripeCnt][0] = i;
                ripeList[ripeCnt][1] = j;
            }
        }
    if (unripeCnt == 0)
    {
        cout << "0\n";
        return 0;
    }

    int day = 0;
    int newRipeCnt = 0, newRipeList[MAX][2];

    while (ripeCnt != 0 && unripeCnt > 0)
    {
        for (; ripeCnt > 0; ripeCnt--)
        {
            int row = ripeList[ripeCnt][0], col = ripeList[ripeCnt][1];

            if (row > 0 && map[row - 1][col] == 0)
            {
                map[row - 1][col] = 1;
                newRipeList[++newRipeCnt][0] = row - 1;
                newRipeList[newRipeCnt][1] = col;
            } // 상

            if (row < N - 1 && map[row + 1][col] == 0)
            {
                map[row + 1][col] = 1;
                newRipeList[++newRipeCnt][0] = row + 1;
                newRipeList[newRipeCnt][1] = col;
            } // 하

            if (col > 0 && map[row][col - 1] == 0)
            {
                map[row][col - 1] = 1;
                newRipeList[++newRipeCnt][0] = row;
                newRipeList[newRipeCnt][1] = col - 1;
            } // 좌

            if (col < M - 1 && map[row][col + 1] == 0)
            {
                map[row][col + 1] = 1;
                newRipeList[++newRipeCnt][0] = row;
                newRipeList[newRipeCnt][1] = col + 1;
            } // 우
        }

        unripeCnt -= newRipeCnt;
        for (; newRipeCnt > 0; newRipeCnt--)
        {
            ripeList[++ripeCnt][0] = newRipeList[newRipeCnt][0];
            ripeList[ripeCnt][1] = newRipeList[newRipeCnt][1];
        }
        day++;
        // cout << "\n";
        // cout << "\n";
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //         cout << map[i][j] << " ";
        //     cout << "\n";
        // }
    }

    if (unripeCnt > 0)
        cout << "-1\n";
    else
        cout << day << "\n";

    return 0;
}