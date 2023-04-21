#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, r, c;
bool isarr = false;
int seek_cnt(int n, int stY, int stX)
{
    if (isarr)
        return 0;
    if (n < 2)
    {
        // cout << stY << ":" << stX << "=>";
        if (stY == r && stX == c)
        {
            isarr = true;
            // cout << "0\n";
            return 0;
        }
        // cout << "1\n";
        return 1;
    }

    int listY[4] = {0, 0, n / 2, n / 2}, listX[4] = {0, n / 2, 0, n / 2}, sum = 0;
    for (int i = 0; i < 4; i++)
        if (!(isarr || stY + listY[i] > r && stX + listX[i] > c))
        {
            if (stY + listY[i] + n / 2 - 1 < r || stX + listX[i] + n / 2 - 1 < c)
            {
                sum += pow(n / 2, 2);
                // cout << "+" << pow(n / 2, 2) << "\n";
            }
            else
                sum += seek_cnt(n / 2, stY + listY[i], stX + listX[i]);
        }

    return sum;
}

int main()
{
    cin >> N >> r >> c;
    cout << seek_cnt(pow(2, N), 0, 0) << "\n";
    return 0;
}