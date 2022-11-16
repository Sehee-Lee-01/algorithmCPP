// 삼성 코테 문제
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, temp, sung_row, sung_column;
        cin >> n >> m;
        int map[n][n];
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
            int start_time = i + 1, min_distance = n * n, min_dis_row = -1, min_dis_col = -1;
            map[sung_row - 1][sung_column - 1] = -1; //갔던 성심당 표시
            vector<int> first_log = {sung_row - 1, sung_column - 1, 0, -1, -1};
            vector<vector<int>> to_move = {first_log};
            while (!to_move.empty())
            {
                int curr_row = to_move.back()[0];
                int curr_column = to_move.back()[1];
                int curr_distance = to_move.back()[2];
                int past_row = to_move.back()[3];
                int past_column = to_move.back()[4];
                to_move.pop_back();

                if (min_distance >= curr_distance) // 거리 같을 떼 작을 때 반영하기
                {
                    if (map[curr_row][curr_column] == 1) // 숙소 도착이라면
                    {
                        if (min_dis_row == curr_row)
                        {
                            if (min_dis_col > curr_column)
                            {
                                min_distance = curr_distance;
                                min_dis_col = curr_column;
                            }
                        }
                        else
                        {
                            min_distance = curr_distance;
                            min_dis_row = curr_row;
                            min_dis_col = curr_column;
                        }
                    }
                    else if (min_distance > curr_distance)
                        // 아니라면 갈 수 있는 길인지 확인하고 이동할 위치에 넣기
                        if ((curr_row > 0) && (map[curr_row - 1][curr_column] != -1)) //상
                            if (!((curr_row - 1 == past_row) && (curr_column == past_column)))
                                to_move.push_back({curr_row - 1, curr_column, curr_distance + 1});
                    if ((curr_row < n - 1) && (map[curr_row + 1][curr_column] != -1)) //하
                        if (!((curr_row - 1 == past_row) && (curr_column == past_column)))
                            to_move.push_back({curr_row + 1, curr_column, curr_distance + 1});
                    if ((curr_column > 0) && (map[curr_row][curr_column - 1] != -1)) //좌
                        if (!((curr_row - 1 == past_row) && (curr_column == past_column)))
                            to_move.push_back({curr_row, curr_column - 1, curr_distance + 1});
                    if ((curr_column < n - 1) && (map[curr_row][curr_column + 1] != -1)) //우
                        if (!((curr_row - 1 == past_row) && (curr_column == past_column)))
                            to_move.push_back({curr_row, curr_column + 1, curr_distance + 1});
                }
            }
            map[min_dis_row][min_dis_col] = -1;
            int arr_time = min_distance + start_time;
            if (max_arr_time < arr_time)
                max_arr_time = arr_time;
        }
        cout << max_arr_time << "\n";
    }
}