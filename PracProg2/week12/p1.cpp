// 올해 공채 문제
// 아직 못품
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int direc_y[] = {-1, 1, 0, 0};
const int direc_x[] = {0, 0, -1, 1};

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin << n;
        vector<vector<char>> climb_map(n, vector<char>(n));
        vector<vector<char>> climb_count(n, vector<char>(n));
        char temp;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> temp;
                climb_map[i][j] = temp;
                if (temp == 'H')
                    climb_count[i][j] = -1;
            }
        // 거꾸로 올라가기
        int curr_y = n - 1, curr_x = 0, curr_count = 1;
        vector<int> to_move = {curr_y, curr_x, curr_count, -1, -1};
        while (!to_move.empty())
        {
            vector<int> curr_info = to_move.back();
            to_move.pop_back;
            // 처음 온 홀드
            if (climb_count[curr_info[0]][curr_info[1]] < 0)
            {
                climb_count[curr_info[0]][curr_info[1]] = curr_count;
            }
            // 기존에 갔던 홀드
            else if (climb_count[curr_info[0]][curr_info[1]] > 0)
            {
                if (curr_count < climb_count[curr_info[0]][curr_info[1]])
                    climb_count[curr_info[0]][curr_info[1]] = curr_count;
            }
            else
                continue;
            // 이동 가능한 경우의 수 5가지
            if (curr_info[0] > 0)
            {
                // 상하좌우
                for (int i = 0; i < 4; i++)
                {
                    if ((climb_map[curr_info[0] + direc_y[i]][curr_info[1] + direc_x[i]] == 'H') && ((curr_info[0] + direc_y[i]) != curr_info[3]) && (curr_info[1] + direc_x[i] != curr_info[4]))
                        to_move.push_back(curr_info[0] + direc_y[i], curr_info[1] + direc_x[i], curr_info[2] + 1, curr_info[0], curr_info[1]);
                }
            }
            // 좌우로 2칸 또는 3칸 떨어진 홀드로 이동
            if (curr_info[1] > 1)
            {
            }
            if (curr_info[1] < n - 1)
            {
            }
            //  윗 칸이 빈칸인 경우 위로 2칸 떨어진 홀드로 이동
            if ()
            {
            }
            // 왼쪽 칸과 윗 칸이 빈칸인 경우 좌상단에 있는 홀드로 이동
            if ()
            {
            }
            // 오른쪽 칸과 윗 칸이 빈칸인 경우 우상단에 있는 홀드로 이동
            if ()
            {
            }
        }
    }
    // result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << climb_count[i][j] << " ";
        cout << "\n";
    }
}
}