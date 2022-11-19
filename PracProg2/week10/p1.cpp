// 삼성 코테 문제
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, temp, sung_row, sung_column;
        cin >> n >> m;
        vector<vector<int>> map(n, vector<int>(n));
        // 숙소 위치 받기
        vector<pair<int, int>> room_places;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> temp;
                map[i][j] = temp;
            }
        // 각 사람이 가고 싶은 성심당에서 가장 가까운 슥소 찾기
        int max_arr_time = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> sung_row >> sung_column;
            int min_distance = n * n, min_dis_row = -1, min_dis_col = -1;
            map[sung_row - 1][sung_column - 1] = -1; //갔던 성심당 표시
            vector<int> first_log = {sung_row - 1, sung_column - 1, 0, -1, -1};
            queue<vector<int>> to_move;
            to_move.push(first_log);
            while (!to_move.empty())
            {
                vector<int> curr_info = to_move.front();
                to_move.pop();

                if (map[curr_info[0]][curr_info[1]] == 1) // 숙소 도착이라면
                {
                    if (min_distance == curr_info[2]) // 가까운 거리정도와 같다면
                    {
                        if (min_dis_row == curr_info[0]) // 이것마저 같다면
                        {
                            if (min_dis_col > curr_info[1]) // 열이 작은거
                                min_dis_col = curr_info[1];
                        }
                        else if (min_dis_row > curr_info[0]) // 행이 작은거
                        {
                            min_dis_row = curr_info[0];
                            min_dis_col = curr_info[1];
                        }
                    }
                    else if (min_distance > curr_info[2]) // 거리가 더 가깝다면
                    {
                        min_distance = curr_info[2];
                        min_dis_row = curr_info[0];
                        min_dis_col = curr_info[1];
                    }
                }

                else if (min_distance >= (curr_info[2] + 1))
                // 아니라면 갈 수 있는 길인지 확인하고 이동할 위치에 넣기(우선순위)
                {
                    if ((curr_info[0] > 0) && (map[curr_info[0] - 1][curr_info[1]] != -1)) //상
                    {
                        if (!((curr_info[0] - 1 == curr_info[3]) && (curr_info[1] == curr_info[4])))
                            to_move.push({curr_info[0] - 1, curr_info[1], curr_info[2] + 1, curr_info[0], curr_info[1]});
                    }
                    if ((curr_info[1] > 0) && (map[curr_info[0]][curr_info[1] - 1] != -1)) //좌
                    {
                        if (!((curr_info[0] == curr_info[3]) && (curr_info[1] - 1 == curr_info[4])))
                            to_move.push({curr_info[0], curr_info[1] - 1, curr_info[2] + 1, curr_info[0], curr_info[1]});
                    }
                    if ((curr_info[1] < n - 1) && (map[curr_info[0]][curr_info[1] + 1] != -1)) //우
                    {
                        if (!((curr_info[0] == curr_info[3]) && (curr_info[1] + 1 == curr_info[4])))
                            to_move.push({curr_info[0], curr_info[1] + 1, curr_info[2] + 1, curr_info[0], curr_info[1]});
                    }
                    if ((curr_info[0] < n - 1) && (map[curr_info[0] + 1][curr_info[1]] != -1)) //하
                    {
                        if (!((curr_info[0] + 1 == curr_info[3]) && (curr_info[1] == curr_info[4])))
                            to_move.push({curr_info[0] + 1, curr_info[1], curr_info[2] + 1, curr_info[0], curr_info[1]});
                    }
                }
            }
            map[min_dis_row][min_dis_col] = -1;
            int arr_time = min_distance + i + 1;

            if (max_arr_time < arr_time)
                max_arr_time = arr_time;
        }
        cout << max_arr_time << "\n"; // result
    }
}