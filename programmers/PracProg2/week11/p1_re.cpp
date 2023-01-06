// 클래스 안만들고 해보기
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Person
{
public:
    pair<int, int> sung_place; // y, x
    pair<int, int> past_place = make_pair(-1, -1);
    pair<int, int> curr_place; // y, x, 이동할 때 필요, 초기값은 숙소 위치
    int curr_dis;              // 숙소와 성심당의 최단거리
    // init
    Person(const int sung_y, const int sung_x, vector<bool> &suk_using, const vector<pair<int, int>> &suk_list, const int n)
    {
        sung_place = make_pair(sung_y, sung_x);
        seekSuk(suk_using, suk_list, n);
    }

    // 초기 최단거리 숙소 찾기(숙소 위치, 숙소와 성심당의 최단거리)
    void seekSuk(vector<bool> &suk_using, const vector<pair<int, int>> &suk_list, const int n)
    {
        curr_dis = n * n;
        int suk_index = -1;
        for (int j = 0; j < suk_using.size(); j++)
        {
            if (!suk_using[j]) // 겹치는 지
            {
                int distance = abs(sung_place.first - suk_list[j].first) + abs(sung_place.second - suk_list[j].second);
                if (curr_dis > distance)
                {
                    curr_dis = distance;
                    curr_place.first = suk_list[j].first;
                    curr_place.second = suk_list[j].second;
                    suk_index = j;
                }
                else if (curr_dis == distance)
                {
                    if (curr_place.first > suk_list[j].first)
                    {
                        curr_place.first = suk_list[j].first;
                        curr_place.second = suk_list[j].second;
                        suk_index = j;
                    }
                    else if ((curr_place.first == suk_list[j].first) && (curr_place.second > suk_list[j].second))
                    {
                        curr_place.second = suk_list[j].second;
                        suk_index = j;
                    }
                }
            }
        }
        suk_using[suk_index] = true;
        // cout << curr_dis << "(" << curr_place.first << ", " << curr_place.second << ")\n";
    }
    // 최적경로 찾기 in on tick(최단 거리 방향)
    void moveRoad(const vector<vector<int>> &map, const int n)
    {
        if (curr_dis == 1)
        {
            curr_dis = 0;
            return;
        }

        pair<int, int> move;
        int min_dis = n * n;

        // 상하좌우 칸이 범위 안에 있는지, 이동이 가능한지()-1이 표시가 안되어 있는지)
        int up = curr_place.first - 1, left = curr_place.second - 1, right = curr_place.second + 1, down = curr_place.first + 1;
        if ((0 <= up) && !((past_place.first == up) && (past_place.second == curr_place.second)) && (map[up][curr_place.second] != -1)) // 이전에 갔던 곳이 아닌지
        {
            int dis = abs(up - sung_place.first) + abs(curr_place.second - sung_place.second);
            if (min_dis > dis) // 최소 거리인지
            {
                move = make_pair(up, curr_place.second);
                min_dis = dis;
            }
        }

        if ((0 <= left) && !((past_place.first == curr_place.first) && (past_place.second == left)) && (map[curr_place.first][left] != -1)) // 이전에 갔던 곳이 아닌지
        {
            int dis = abs(curr_place.first - sung_place.first) + abs(left - sung_place.second);
            if (min_dis > dis) // 최소 거리인지
            {
                move = make_pair(curr_place.first, left);
                min_dis = dis;
            }
        }

        if ((right < n) && !((past_place.first == curr_place.first) && (past_place.second == right)) && (map[curr_place.first][right] != -1)) // 이전에 갔던 곳이 아닌지
        {
            int dis = abs(curr_place.first - sung_place.first) + abs(right - sung_place.second);
            if (min_dis > dis) // 최소 거리인지
            {
                move = make_pair(curr_place.first, right);
                min_dis = dis;
            }
        }

        if ((down < n) && !((past_place.first == down) && (past_place.second == curr_place.second)) && (map[down][curr_place.second] != -1)) // 이전에 갔던 곳이 아닌지
        {
            int dis = abs(down - sung_place.first) + abs(curr_place.second - sung_place.second);
            if (min_dis > dis) // 최소 거리인지
            {
                move = make_pair(down, curr_place.second);
                min_dis = dis;
            }
        }

        past_place = curr_place;
        curr_place = move;
        curr_dis = min_dis;
    }
};

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
        vector<pair<int, int>> suk_list; // 숙소 위치 받아서 맵에 표시하고 저장
        int suk_count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> temp;
                map[i][j] = temp;
                if (temp == 1) // 숙소면 숙소 리스트에 저장
                {
                    suk_list.push_back(make_pair(i, j));
                    suk_count++;
                }
            }

        // 성심당 위치와 숙소 위치 저장
        vector<bool> suk_using(suk_count, false);
        // cout << "suk_count " << suk_count << "\n";
        vector<Person> person_list;
        vector<bool> is_arrive = vector<bool>(m, false); // 성심당 도착 사람
        int wait_num = m, arrive_num = 0;                // 사람 수
        int time = 0;
        vector<pair<int, int>> unable_move; // 다 움직인 직후에 숙소를 떠난 위치가 있다면 기록
        while (arrive_num < m)              //  다 이동 완료 할 때까지
        {
            for (int i = 0; i < person_list.size(); i++) // 개인씩 우선 이동
            {
                if (!is_arrive[i]) // 도착한 사람 구분
                {
                    person_list[i].moveRoad(map, n);
                    // cout << "person" << i << ": " << person_list[i].curr_dis << "\n";
                    if (person_list[i].curr_dis == 0) // 도착이라면
                    {
                        unable_move.push_back(make_pair(person_list[i].sung_place.first, person_list[i].sung_place.second));
                        is_arrive[i] = true;
                        arrive_num++;
                    }
                }
            }

            while (!unable_move.empty())
            {
                // cout << "(" << unable_move.back().first << ", " << unable_move.back().second << ")"
                //      << "\n";
                map[unable_move.back().first][unable_move.back().second] = -1;
                unable_move.pop_back();
            }
            if (wait_num)
            {
                cin >> sung_row >> sung_column;
                person_list.push_back(Person(sung_row - 1, sung_column - 1, suk_using, suk_list, n));
                map[person_list[person_list.size() - 1].curr_place.first][person_list[person_list.size() - 1].curr_place.second] = -1;
                // cout << m - wait_num << "curr_dis: " << person_list[m - wait_num].curr_dis << "\n";
                wait_num--;
            }
            time++;
            // cout << "time: " << time << "==================================\n";
            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < n; j++)
            //     {
            //         cout << map[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
        }
        cout << time << "\n";
    }
}