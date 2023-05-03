#include <iostream>
#include <vector>
using namespace std;
int direc_y[] = {-1, 0, 1, 0};
int direc_x[] = {0, 1, 0, -1};

int main()
{
    int t, n, d, r, c, temp;
    cin >> t;
    while (t--)
    {
        cin >> n >> d >> r >> c; // 격자 크기와 방향, 행과 열
        // 격자 입력받기
        vector<vector<int>> map = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> temp;
                map[i][j] = temp;
            }
        }
        vector<int> currinfo = {r, c, d};
        vector<int> pastinfo = {-1, -1, -1};
        int clean_count = 0;
        // 시작(벽:1, 안청소:0, 청소:-1)
        while (1)
        {
            pastinfo = currinfo;
            if (map[currinfo[0]][currinfo[1]] == 0)
            {
                map[currinfo[0]][currinfo[1]] = -1;
                clean_count++;
            }

            int next_d = d;
            for (int i = 1; i <= 4; i++)
            {
                next_d--;
                if (next_d < 0)
                    next_d = 3;
                int y = currinfo[0] + direc_y[next_d];
                int x = currinfo[1] + direc_x[next_d];
                if (0 <= y && y < n && 0 <= x && x < n && map[y][x] == 0)
                {
                    d = next_d;
                    currinfo = {y, x, d};
                    break;
                }
            }

            // 규칙 2-3
            if (next_d == d && (currinfo[0] == pastinfo[0] && currinfo[1] == pastinfo[1]))
            {
                int y = currinfo[0] - direc_y[next_d];
                int x = currinfo[1] - direc_x[next_d];
                if (0 <= y && y < n && 0 <= x && x < n && map[y][x] != 1)
                {
                    currinfo = {y, x, d};
                    continue;
                }
                else
                    break;
            }
        }
        cout << clean_count << "\n";
    }
}