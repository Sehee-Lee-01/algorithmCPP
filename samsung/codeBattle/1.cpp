// bfs
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        int R, C;
        cin >> R >> C;

        string temp;
        int map[R][C];
        for (int i = 0; i < R; i++)
        {
            cin >> temp;
            for (int j = 0; j < C; j++)
                map[i][j] = temp[j] - 'A';
        }

        int res = 0;
        vector<int> st_info = vector<int>(29); // [0:25]: past_기념품 종류, [26]: past_count, [27]: curr_y, [28]: curr_x;
        vector<vector<int>> to_go = {st_info};
        while (!to_go.empty())
        {
            vector<int> curr_info = to_go.back();
            to_go.pop_back();

            curr_info[map[curr_info[27]][curr_info[28]]]++; // 기념품 업데이트
            curr_info[26]++;                                // 총 개수 업데이트

            if (res < curr_info[26])
                res = curr_info[26];
            if (res == 26)
            {
                res = 26;
                break;
            }

            // 이동
            vector<int> temp_info;
            if (curr_info[27] > 0 && !curr_info[map[curr_info[27] - 1][curr_info[28]]]) // 위
            {
                temp_info = curr_info;
                temp_info[27]--;
                to_go.push_back(temp_info);
            }

            if (curr_info[27] < R - 1 && !curr_info[map[curr_info[27] + 1][curr_info[28]]]) // 아래
            {
                temp_info = curr_info;
                temp_info[27]++;
                to_go.push_back(temp_info);
            }

            if (curr_info[28] > 0 && !curr_info[map[curr_info[27]][curr_info[28] - 1]]) // 왼
            {
                temp_info = curr_info;
                temp_info[28]--;
                to_go.push_back(temp_info);
            }

            if (curr_info[28] < C - 1 && !curr_info[map[curr_info[27]][curr_info[28] + 1]]) // 오른
            {
                temp_info = curr_info;
                temp_info[28]++;
                to_go.push_back(temp_info);
            }
        }

        cout << "#" << test_case << " " << res << "\n";
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}