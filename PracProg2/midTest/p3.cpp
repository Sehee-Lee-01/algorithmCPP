// 차차차
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int road[N + 1][5], score[N + 1][5], temp;
        // 시작 전 라인 초기화
        for (int j = 0; j < 5; j++)
            score[0][j] = -1;
        score[0][2] = 0;

        // 0열 제외하고 받으면서 디폴트 점수 기록
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> temp;
                road[i][j] = temp;
                score[i][j] = -1;
            }
        }

        // 주행 시작
        vector<vector<int>> toVisit; // {라인, 현재위치}
        toVisit.push_back({1, 2});   // 여기서부터 시작

        while (!toVisit.empty())
        {
            int line = toVisit.back()[1];
            int currLoc = toVisit.back()[1];
            toVisit.pop_back();

            if (road[line][currLoc] != 1) // 장애물 확인
            {
                score[line][currLoc] = 0;
                if ((currLoc > 0) && (currLoc == 1)) // 왼 장애물 확인
                    score[line][currLoc]++;
                if ((currLoc > 4) && (currLoc == 1)) // 오른 장애물 확인
                    score[line][currLoc]++;
                if (line > 1) // 직전 점수 중 최대 점수로 합산하기
                {
                    int maxScore = 0;
                    if ((road[line - 1][currLoc] != 1) && (score[line - 1][currLoc] > maxScore))
                        maxScore = score[line - 1][currLoc];
                    if ((currLoc < 4) && (road[line - 1][currLoc + 1] != 1) && (score[line - 1][currLoc] > maxScore))
                        maxScore = score[line - 1][currLoc];
                    if ((currLoc > 0) && (road[line - 1][currLoc - 1] != 1) && (score[line - 1][currLoc] > maxScore))
                        maxScore = score[line - 1][currLoc];
                }
            }

            if ((line < N - 1) && (road[line + 1][currLoc] != 1)) // 다음에 갈 직진
                toVisit
        }

        int max = 0;
        for (int j = 0; j < 5; j++)
            if (max < score[N][j])
                max = score[N][j];

        cout << max << '\n';
    }
}