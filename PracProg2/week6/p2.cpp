// 편세권
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void makeScoreLayer(int n, vector<vector<int>> &map, int con_y, int con_x)
{
    for (int j = con_y - 10; j <= con_y + 10; j++)
    {
        for (int k = con_x - 10; k <= con_x + 10; k++)
        {
            // 맵의 범위 내에 들어오고 편의점 위치가 아닌 곳을 탐색
            if ((0 <= j) && (j < n) && (0 <= k) && (k < n) && (map[j][k] != -1))
            {
                if ((abs(j - con_y) + abs(k - con_x)) <= 3) // 맨하튼 거리가 3이하일 경우 +3
                    map[j][k] += 3;
                else if ((abs(j - con_y) + abs(k - con_x)) <= 10) // 맨하튼 거리가 3초과 10이하일 경우 +1
                    map[j][k] += 1;
            }
        }
    }
}

int main()
{
    int t, n, c, con_y, con_x;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++)
    {
        cin >> n >> c;
        vector<vector<int>> map(n, vector<int>(n)); //[n][n] 0으로 초기화

        for (int i = 0; i < c; i++) // 입력 받으면서 지도에 점수 레이어 씌우기
        {
            cin >> con_y >> con_x;
            map[con_y][con_x] = -1;
            makeScoreLayer(n, map, con_y, con_x); // map에 1점, 2점 점수 채우기
        }

        // 최댓값, 그 값의 좌표 순회하기
        int max_score = 0, max_y, max_x;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (max_score < map[i][j])
                {
                    max_score = map[i][j];
                    max_y = i;
                    max_x = j;
                }
            }
        }

        // 결과 출력
        cout << max_y << " " << max_x << " " << max_score << '\n';
    }
}