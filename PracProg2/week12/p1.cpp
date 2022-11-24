// 올해 공채 문제
// 아직 못품
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> climb_map(n, vector<int>(n, 0));
        char temp;
        // 거꾸로 입력받기, 홀드 = -1, 이동불가 = -2, 빈칸 = 0
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j < n; j++)
            {
                cin >> temp;
                switch (temp)
                {
                case 'H':
                    climb_map[i][j] = -1;
                    break;
                case 'X':
                    climb_map[i][j] = -2;
                    break;
                }
            }

        // BFS
        int curr_y = 0, curr_x = 0, curr_count = 1;
        vector<int> start = {curr_y, curr_x, curr_count, -1, -1};
        vector<vector<int>> to_move;
        to_move.push_back(start);
        while (!to_move.empty())
        {
            vector<int> curr_info = to_move.back();
            to_move.pop_back();

            // 처음 온 홀드
            if (climb_map[curr_info[0]][curr_info[1]] == -1)
            {
                climb_map[curr_info[0]][curr_info[1]] = curr_info[2];
            }
            // 기존에 갔던 홀드이면서 더 최소거리로 왔을 경우
            else if (climb_map[curr_info[0]][curr_info[1]] > curr_info[2])
            {
                climb_map[curr_info[0]][curr_info[1]] = curr_info[2];
            }
            else
                continue;

            vector<bool> isEmpty = {false, false, false, false}; // 싱하좌우 빈칸인지
                                                                 // 위 조건문 넘어온 후 갈 수 있는 방향 push
            // 상
            if ((curr_info[0] + 1) < n)
            {
                if ((climb_map[curr_info[0] + 1][curr_info[1]] != -2) && (climb_map[curr_info[0] + 1][curr_info[1]] != 0)) // 갈 수 있을 때
                {
                    if (!((curr_info[3] == (curr_info[0] + 1)) && (curr_info[4] == (curr_info[1])))) // 이전과 다를 떼
                        to_move.push_back({curr_info[0] + 1, curr_info[1], curr_info[2] + 1, curr_info[0], curr_info[1]});
                }
                else if (climb_map[curr_info[0] + 1][curr_info[1]] == 0) // 빈칸일 때
                    isEmpty[0] = true;
            }
            // 하
            if ((curr_info[0] - 1) >= 0)
            {
                if ((climb_map[curr_info[0] - 1][curr_info[1]] != -2) && (climb_map[curr_info[0] - 1][curr_info[1]] != 0)) // 갈 수 있을 때
                {
                    if (!((curr_info[3] == (curr_info[0] - 1)) && (curr_info[4] == (curr_info[1])))) // 이전과 다를 떼
                        to_move.push_back({curr_info[0] - 1, curr_info[1], curr_info[2] + 1, curr_info[0], curr_info[1]});
                }
                else if (climb_map[curr_info[0] - 1][curr_info[1]] == 0) // 빈칸일 때
                    isEmpty[1] = true;
                // 좌
            }
            if ((curr_info[1] - 1) >= 0)
            {
                if ((climb_map[curr_info[0]][curr_info[1] - 1] != -2) && (climb_map[curr_info[0]][curr_info[1] - 1] != 0)) // 갈 수 있을 때
                {
                    if (!((curr_info[3] == curr_info[0]) && (curr_info[4] == (curr_info[1] - 1)))) // 이전과 다를 떼
                        to_move.push_back({curr_info[0], curr_info[1] - 1, curr_info[2] + 1, curr_info[0], curr_info[1]});
                }
                else if (climb_map[curr_info[0]][curr_info[1] - 1] == 0) // 빈칸일 때
                    isEmpty[2] = true;
            }
            // 우
            if ((curr_info[1] + 1) < n)
            {
                if ((climb_map[curr_info[0]][curr_info[1] + 1] != -2) && (climb_map[curr_info[0]][curr_info[1] + 1] != 0)) // 갈 수 있을 때
                {
                    if (!((curr_info[3] == curr_info[0]) && (curr_info[4] == (curr_info[1] + 1)))) // 이전과 다를 떼
                        to_move.push_back({curr_info[0], curr_info[1] + 1, curr_info[2] + 1, curr_info[0], curr_info[1]});
                }
                else if (climb_map[curr_info[0]][curr_info[1] + 1] == 0) // 빈칸일 때
                    isEmpty[3] = true;
            }

            // 상하좌우 체크 후 나머지 조건 확인
            if (isEmpty[0])
            {
                if ((curr_info[0] + 2 < n) && (climb_map[curr_info[0] + 2][curr_info[1]] != -2) && (climb_map[curr_info[0] + 2][curr_info[1]] != 0)) // 조건 3
                    to_move.push_back({curr_info[0] + 2, curr_info[1], curr_info[2] + 1, curr_info[0], curr_info[1]});

                if (isEmpty[2]) // 좌가 빈칸일 경우 생각할 수 있는 경우
                {
                    if ((climb_map[curr_info[0] + 1][curr_info[1] - 1] != -2) && (climb_map[curr_info[0] + 1][curr_info[1] - 1] != 0)) // 조건 4
                        to_move.push_back({curr_info[0] + 1, curr_info[1] - 1, curr_info[2] + 1, curr_info[0], curr_info[1]});

                    // 좌 건너뛰기, 이전위치 확인필요
                    if ((curr_info[1] - 2 >= 0) && (climb_map[curr_info[0] + 1][curr_info[1] - 1] == 0) && (climb_map[curr_info[0] + 1][curr_info[1] - 2] == 0))
                    {
                        if (climb_map[curr_info[0]][curr_info[1] - 2] == 0)
                        {
                            if ((curr_info[1] - 3 >= 0) && (climb_map[curr_info[0] + 1][curr_info[1] - 3] == 0))
                                if ((climb_map[curr_info[0]][curr_info[1] - 3] != 0) && (climb_map[curr_info[0]][curr_info[1] - 3] != -2))
                                    if (!((curr_info[0] == curr_info[3]) && ((curr_info[1] - 3) == curr_info[4])))
                                        to_move.push_back({curr_info[0], curr_info[1] - 3, curr_info[2] + 1, curr_info[0], curr_info[1]});
                            // 이전 위치 체크
                        }
                        else if (climb_map[curr_info[0]][curr_info[1] - 2] != -2)
                            if (!((curr_info[0] == curr_info[3]) && ((curr_info[1] - 2) == curr_info[4]))) // 이전 위치 체크
                                to_move.push_back({curr_info[0], curr_info[1] - 2, curr_info[2] + 1, curr_info[0], curr_info[1]});
                    }
                }
                if (isEmpty[3]) // 우가 빈칸일 경우 생각할 수 있는 경우
                {
                    if ((climb_map[curr_info[0] + 1][curr_info[1] + 1] != -2) && (climb_map[curr_info[0] + 1][curr_info[1] + 1] != 0)) // 조건 5
                        to_move.push_back({curr_info[0] + 1, curr_info[1] + 1, curr_info[2] + 1, curr_info[0], curr_info[1]});

                    // 우 건너뛰기, 이전위치 확인필요
                    if ((curr_info[1] + 2 < n) && (climb_map[curr_info[0] + 1][curr_info[1] + 1] == 0) && (climb_map[curr_info[0] + 1][curr_info[1] + 2] == 0))
                    {
                        if (climb_map[curr_info[0]][curr_info[1] + 2] == 0)
                        {
                            if ((curr_info[1] + 3 >= 0) && (climb_map[curr_info[0] + 1][curr_info[1] + 3] == 0))
                                if ((climb_map[curr_info[0]][curr_info[1] + 3] != 0) && (climb_map[curr_info[0]][curr_info[1] + 3] != -2))
                                    if (!((curr_info[0] == curr_info[3]) && ((curr_info[1] + 3) == curr_info[4])))
                                        to_move.push_back({curr_info[0], curr_info[1] + 3, curr_info[2] + 1, curr_info[0], curr_info[1]});
                            // 이전 위치 체크
                        }
                        else if (climb_map[curr_info[0]][curr_info[1] + 2] != -2)
                            if (!((curr_info[0] == curr_info[3]) && ((curr_info[1] + 2) == curr_info[4]))) // 이전 위치 체크
                                to_move.push_back({curr_info[0], curr_info[1] + 2, curr_info[2] + 1, curr_info[0], curr_info[1]});
                    }
                }
            }
        }
        // result
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
