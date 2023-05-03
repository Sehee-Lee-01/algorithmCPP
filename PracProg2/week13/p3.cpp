/*과일숙성*/
#include <iostream>
#include <vector>
using namespace std;

int y_direc[] = {1, -1, 0, 0};
int x_direc[] = {0, 0, 1, -1};

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int temp;
        vector<vector<int>> map = vector<vector<int>>(n, vector<int>(m));
        vector<pair<int, int>> to_move; // 바로 전 타임에 방금 익은 사과들 넣기
        int non_ripe_count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> temp;
                map[i][j] = temp;
                if (temp == 1)
                    to_move.push_back(make_pair(i, j));
                else if (temp == 0)
                    non_ripe_count++;
            }

        int time = 0;
        while (!to_move.empty())
        {
            int past_non_ripe_count = non_ripe_count;
            vector<pair<int, int>> new_ripe;
            // 한타임 시작
            while (!to_move.empty())
            {
                pair<int, int> ripe = to_move.back();
                to_move.pop_back();

                for (int j = 0; j < 4; j++)
                {
                    int y = ripe.first + y_direc[j];
                    int x = ripe.second + x_direc[j];
                    if (0 <= y && y < n && 0 <= x && x < m && map[y][x] == 0)
                    {
                        non_ripe_count--;
                        map[y][x] = 1;
                        new_ripe.push_back(make_pair(y, x));
                    }
                }
            }
            if (new_ripe.empty())
                break;
            while (!new_ripe.empty())
            {
                to_move.push_back(new_ripe.back());
                new_ripe.pop_back();
            }
            time++;
        }
        if (non_ripe_count > 0)
            cout << "-1\n";
        else
            cout << time << "\n";
    }
}