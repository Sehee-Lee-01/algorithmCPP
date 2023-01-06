#include <iostream>
#include <vector>
using namespace std;

// 상 하 좌 우
int dir_y[4] = {1, -1, 0, 0};
int dir_x[4] = {0, 0, -1, 1};

int main()
{
    int t, n;
    char temp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> climb_map = vector<vector<int>>(n, vector<int>(n));
        // 빈칸 . = 0, 이동불가 X = -2, 홀드 = H = -1
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> temp;
                switch (temp)
                {
                case '.':
                    climb_map[i][j] = 0;
                    break;
                case 'X':
                    climb_map[i][j] = -2;
                    break;
                default:
                    climb_map[i][j] = -1;
                    break;
                }
            }
        }

        // 클라이밍 시작
        vector<vector<int>> to_move;
        to_move.push_back({0, 0, 1, -1, -1});

        while (!to_move.empty())
        {
            vector<int> curr = to_move.back();
            to_move.pop_back();

            if ((climb_map[curr[0]][curr[1]] == -1) || (climb_map[curr[0]][curr[1]] > curr[2]))
            {
                climb_map[curr[0]][curr[1]] = curr[2];
            }
            bool isEmpty[4] = {false, false, false, false}; // 상 하 좌 우

            // for (int i = 0; i < 4; i++) // 상하좌우 탐색
            // {
            //     if ((curr[0] + dir_y[i] >= 0) && (curr[0] + dir_y[i] < n) && (curr[1] + dir_x[i] >= 0) && (curr[1] + dir_x[i] < n))
            //     {
            //         if ((climb_map[curr[0] + dir_y[i]][curr[1] + dir_x[i]] == -1) || (climb_map[curr[0] + dir_y[i]][curr[1] + dir_x[i]] > 0))
            //         {
            //             if (!((curr[0] + dir_y[i] == curr[3]) && (curr[1] + dir_x[i] == curr[4])))
            //             {
            //                 to_move.push_back({curr[0] + dir_y[i], curr[1] + dir_x[i], curr[2] + 1, curr[0], curr[1]});
            //             }
            //         }
            //         else if (climb_map[curr[0] + dir_y[i]][curr[1] + dir_x[i]] == 0)
            //         {
            //             isEmpty[i] = true;
            //         }
            //     }
            // }
            // up
            if (curr[0] + 1 < n)
            {
                if ((climb_map[curr[0] + 1][curr[1]] == -1) || (climb_map[curr[0] + 1][curr[1]] > 0))
                {
                    if (!((curr[0] + 1 == curr[3]) && (curr[1] == curr[4])))
                    {
                        to_move.push_back({curr[0] + 1, curr[1], curr[2] + 1, curr[0], curr[1]});
                    }
                }
                else if (climb_map[curr[0] + 1][curr[1]] == 0)
                {
                    isEmpty[0] = true;
                    if ((curr[0] + 2 < n) && ((climb_map[curr[0] + 2][curr[1]] == -1) || (climb_map[curr[0] + 2][curr[1]] > 0))) // 3
                    {
                        if (!((curr[0] + 2 == curr[3]) && (curr[1] == curr[4])))
                            to_move.push_back({curr[0] + 2, curr[1], curr[2] + 1, curr[0], curr[1]});
                    }
                }
            }
            // down
            if (curr[0] - 1 >= 0)
            {
                if ((climb_map[curr[0] - 1][curr[1]] == -1) || (climb_map[curr[0] - 1][curr[1]] > 0))
                {
                    if (!((curr[0] - 1 == curr[3]) && (curr[1] == curr[4])))
                    {
                        to_move.push_back({curr[0] - 1, curr[1], curr[2] + 1, curr[0], curr[1]});
                    }
                }
                else if (climb_map[curr[0] - 1][curr[1]] == 0)
                {
                    isEmpty[1] = true;
                }
            }

            if (curr[1] - 1 >= 0)
            {
                if ((climb_map[curr[0]][curr[1] - 1] == -1) || (climb_map[curr[0]][curr[1] - 1] > 0))
                {
                    if (!((curr[0] == curr[3]) && (curr[1] - 1 == curr[4])))
                    {
                        to_move.push_back({curr[0], curr[1] - 1, curr[2] + 1, curr[0], curr[1]});
                    }
                }
                else if (climb_map[curr[0]][curr[1] - 1] == 0)
                {
                    isEmpty[2] = true;

                    if (isEmpty[2]) // 좌 빈칸 규칙
                    {
                        if (isEmpty[0])
                        {
                            if ((climb_map[curr[0] + 1][curr[1] - 1] == 0) && (curr[1] - 2 >= 0)) // 규칙 2
                            {
                                if (climb_map[curr[0] + 1][curr[1] - 2] == 0)
                                {
                                    if ((climb_map[curr[0]][curr[1] - 2] == -1) || (climb_map[curr[0]][curr[1] - 2] > 0))
                                    {
                                        if (!((curr[0] == curr[3]) && (curr[1] - 2 == curr[4])))
                                            to_move.push_back({curr[0], curr[1] - 2, curr[2] + 1, curr[0], curr[1]});
                                        // cout << "3test\n";
                                    }
                                    else if ((climb_map[curr[0]][curr[1] - 2] == 0) && (curr[1] - 3 >= 0))
                                    {
                                        if ((climb_map[curr[0] + 1][curr[1] - 3] == 0) && ((climb_map[curr[0]][curr[1] - 3] == -1) || (climb_map[curr[0]][curr[1] - 3] > 0)))
                                        {
                                            if (!((curr[0] == curr[3]) && (curr[1] - 3 == curr[4])))
                                                to_move.push_back({curr[0], curr[1] - 3, curr[2] + 1, curr[0], curr[1]});
                                        }
                                    }
                                }
                            }
                            else if ((climb_map[curr[0] + 1][curr[1] - 1] == -1) || (climb_map[curr[0] + 1][curr[1] - 1] > 0)) // 4
                            {
                                if (!((curr[0] + 1 == curr[3]) && (curr[1] - 1 == curr[4])))
                                    to_move.push_back({curr[0] + 1, curr[1] - 1, curr[2] + 1, curr[0], curr[1]});
                            }
                        }
                    }
                }
            }
            if (isEmpty[3]) // 우 규칙
            {
                if (isEmpty[0])
                {
                    if ((climb_map[curr[0] + 1][curr[1] + 1] == 0) && (curr[1] + 2 < n)) // 규칙 2
                    {
                        if (climb_map[curr[0] + 1][curr[1] + 2] == 0)
                        {
                            if ((climb_map[curr[0]][curr[1] + 2] == -1) || (climb_map[curr[0]][curr[1] + 2] > 0))
                            {
                                if (!((curr[0] == curr[3]) && (curr[1] + 2 == curr[4])))
                                    to_move.push_back({curr[0], curr[1] + 2, curr[2] + 1, curr[0], curr[1]});
                            }
                            else if ((climb_map[curr[0]][curr[1] + 2] == 0) && (curr[1] + 3 < n))
                            {
                                if ((climb_map[curr[0] + 1][curr[1] + 3] == 0) && ((climb_map[curr[0]][curr[1] + 3] == -1) || (climb_map[curr[0]][curr[1] + 3] > 0)))
                                    if (!((curr[0] == curr[3]) && (curr[1] + 3 == curr[4])))
                                        to_move.push_back({curr[0], curr[1] + 3, curr[2] + 1, curr[0], curr[1]});
                            }
                        }
                    }
                    else if ((climb_map[curr[0] + 1][curr[1] + 1] == -1) || (climb_map[curr[0] + 1][curr[1] + 1] > 0)) // 5
                        if (!((curr[0] + 1 == curr[3]) && (curr[1] + 1 == curr[4])))
                            to_move.push_back({curr[0] + 1, curr[1] + 1, curr[2] + 1, curr[0], curr[1]});
                }
            }
        }

        // 출력
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (climb_map[i][j] == -2)
                    cout << 0 << " ";
                else
                    cout << climb_map[i][j] << " ";
            }
            cout << "\n";
        }
    }
}