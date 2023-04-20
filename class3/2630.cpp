#include <iostream>
using namespace std;
#define MAX 128

int square[MAX][MAX];
int white = 0, blue = 0;

int divide_paper(int N, int stY, int stX)
{
    if (N < 2)
        return square[stY][stX];

    int halfSquares[4], valY[4] = {0, 0, N / 2, N / 2}, valX[4] = {0, N / 2, 0, N / 2};
    for (int i = 0; i < 4; i++)
    {
        halfSquares[i] = divide_paper(N / 2, stY + valY[i], stX + valX[i]);
        // cout << "halfSquares[i]: " << halfSquares[i] << "\n";
        // cout << "stY + valY[i]: " << stY + valY[i] << "\n";
        // cout << "stX + valX[i]: " << stX + valX[i] << "\n";
    }
    if (halfSquares[0] == 1 && halfSquares[1] == 1 && halfSquares[2] == 1 && halfSquares[3] == 1)
        return 1;
    else if (halfSquares[0] == 0 && halfSquares[1] == 0 && halfSquares[2] == 0 && halfSquares[3] == 0)
        return 0;
    else
    {
        for (int i = 0; i < 4; i++)
            if (halfSquares[i] == 1)
                blue++;
            else if (halfSquares[i] == 0)
                white++;
        return -1;
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> square[i][j];

    int res = divide_paper(N, 0, 0);
    if (res == 1)
        blue++;
    else if (res == 0)
        white++;

    cout << white << "\n";
    cout << blue << "\n";
    return 0;
}