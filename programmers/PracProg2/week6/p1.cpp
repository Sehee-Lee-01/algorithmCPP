//사다리타기 2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, m, d;
    string temp;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> d;
        int row_length = n * 2 - 1, unknown_row = -1;
        string ladder[m];                // 미리 공간 만들기
        for (int i = m - 1; i >= 0; i--) // 줄 갯수
        {
            cin >> temp;
            ladder[i] = temp;
            if (ladder[i][0] == '?')
                unknown_row = i;
        }
        // cout << unknown_row << '\n';

        // 공간 만들고, ? 행 전까지는 길 찾기 시작
        int curr_location = 2 * d - 2;
        for (int i = 0; i < unknown_row; i++)
        {
            // 왼쪽 이동이 가능할 때
            if ((1 < curr_location) && (ladder[i][curr_location - 1] == '+'))
                curr_location -= 2;
            //오른쪽 이동이 가능할 때
            else if ((curr_location < (row_length - 2)) && (ladder[i][curr_location + 1] == '+'))
                curr_location += 2;
            // cout << curr_location << '\n';
        }

        vector<int> curr_locations;
        curr_locations.push_back(curr_location); // 1. 직진 길 curr_locations[1]
        // ? 행일 때 curr_location 직진, 양 옆 확인
        if (1 < curr_location) // 2. 왼쪽 길 만들 수 있는지 curr_locations[0]
            curr_locations.push_back(curr_location - 2);

        if (curr_location < (row_length - 2)) // 3. 오른쪽 길 만들 수 있는지 curr_locations[2]
            curr_locations.push_back(curr_location + 2);

        // cout << row_length << '\n';

        // ? 행 이후로 길 찾기
        for (int i = unknown_row + 1; i < m; i++)
        {
            for (int j = 0; j < curr_locations.size(); j++)
            {
                // 왼쪽 이동이 가능할 때
                if ((1 < curr_locations[j]) && (ladder[i][curr_locations[j] - 1] == '+'))
                    curr_locations[j] -= 2;
                //오른쪽 이동이 가능할 때
                else if ((curr_locations[j] < (row_length - 2)) && (ladder[i][curr_locations[j] + 1] == '+'))
                    curr_locations[j] += 2;
            }
        }

        // 정렬
        sort(curr_locations.begin(), curr_locations.end());

        // 출력
        for (int i = 0; i < curr_locations.size(); i++)
            cout << (curr_locations[i] + 2) / 2 << " ";
        cout << '\n';
    }
}