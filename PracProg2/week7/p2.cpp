#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

// m 분 후 시체 피해 지역 그리기, 사각형
void drawMinusZone(vector<vector<ll>> &safe_zone, int n, int m, int r, int c)
{
    int starty = r - m, endy = r + m, startx = c - m, endx = c + m;
    if (starty < 0)
        starty = 0;
    if (n < endy)
        endy = n - 1;
    if (startx < 0)
        startx = 0;
    if (n < endx)
        endx = n - 1;

    for (int i = starty; i <= endy; i++)
        for (int j = startx; j <= endx; j++)
        {
            int diff = abs(j - c);
            if (abs(i - r) > abs(j - c))
                diff = abs(i - r);
            safe_zone[i][j] -= (m + 1 - diff);
        }
}

// m 분 후 치유 헤택 지역 그리기, 마름모
void drawPlusZone(vector<vector<ll>> &safe_zone, int n, int m, int r, int c)
{
    int starty = r - m, endy = r + m, startx = c - m, endx = c + m;
    if (starty < 0)
        starty = 0;
    if (n < endy)
        endy = n - 1;
    if (startx < 0)
        startx = 0;
    if (n < endx)
        endx = n - 1;

    for (int i = starty; i <= endy; i++)
        for (int j = startx; j <= endx; j++)
            if ((abs(i - r) + abs(j - c)) <= m)
                safe_zone[i][j] += (m + 1 - (abs(i - r) + abs(j - c)));
}

int main()
{
    int t, n, m, a, b, r, c;
    // 맵 만들기(0초기화)
    scanf("%d", &t);
    // cin >> t;
    while (t--)
    {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        // cin >> n >> m >> a >> b;
        vector<vector<ll>> safe_zone(n, vector<ll>(n));
        // 시체 a개
        for (int i = 0; i < a; i++)
        {
            scanf("%d %d", &r, &c);
            // cin >> r >> c;
            drawMinusZone(safe_zone, n, m, r, c);
            safe_zone[r][c]++;
        }
        // 치유 b개
        for (int i = 0; i < b; i++)
        {
            scanf("%d %d", &r, &c);
            // cin >> r >> c;
            drawPlusZone(safe_zone, n, m, r, c);
            safe_zone[r][c]--;
        }
        // m 분 후의 안전지대(n*n)의 상황을 출력
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                // cout << safe_zone[i][j] << " ";
                printf("%lld ", safe_zone[i][j]);

            // cout << '\n';
            printf("\n");
        }
    }
}