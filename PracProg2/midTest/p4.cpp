// 치유와드
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 정사각형모양
void siche(vector<vector<int>> &map, int m, int n, int tempY, int tempX)
{
    int startY = tempY - m, endY = tempY + m;
    int startX = tempX - m, endX = tempX + m;
    if (startY < 0)
        startY = 0;
    if (endY > n - 1)
        endY = n - 1;
    if (startX < 0)
        startX = 0;
    if (endX > n - 1)
        endX = n - 1;
    for (int i = startY; i <= endY; i++)
    {
        for (int j = startX; j <= endX; j++)
        {

            if (abs(tempY - i) > abs(tempX - j))
                map[i][j] -= (m + 1 - abs(tempY - i));
            else
                map[i][j] -= (m + 1 - abs(tempX - j));
        }
    }
    map[tempY][tempX]++;
};
// 마름모 모양
void heal(vector<vector<int>> &map, int m, int n, int tempY, int tempX)
{
    int startY = tempY - m, endY = tempY + m;
    int startX = tempX - m, endX = tempX + m;
    if (startY < 0)
        startY = 0;
    if (endY > n - 1)
        endY = n - 1;
    if (startX < 0)
        startX = 0;
    if (endX > n - 1)
        endX = n - 1;
    for (int i = startY; i <= endY; i++)
    {
        for (int j = startX; j <= endX; j++)
        {
            if ((abs(tempY - i) + abs(tempX - j)) <= m)
                map[i][j] += (m + 1 - (abs(tempY - i) + abs(tempX - j)));
        }
    }
    map[tempY][tempX]--;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b, tempY, tempX;
        cin >> n >> m >> a >> b;
        vector<vector<int>> map = vector<vector<int>>(n, vector<int>(n, 0));
        // 시체 행열
        for (int i = 0; i < a; i++)
        {
            cin >> tempY >> tempX;
            siche(map, m, n, tempY, tempX);
        }
        // 치유 행열
        for (int i = 0; i < b; i++)
        {
            cin >> tempY >> tempX;
            heal(map, m, n, tempY, tempX);
        }
        // 행열 출력
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << map[i][j] << ' ';
            cout << '\n';
        }
    }
}