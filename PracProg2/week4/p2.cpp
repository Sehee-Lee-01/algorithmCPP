// 차차차
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int t, N;
int direc[3] = {-1, 0, 1};
int check_side[2] = {-1, 1};

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> N;
        int max_score = -1, temp, road[N][5], dp_score[N][5]; //[y][x]
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> temp;
                road[i][j] = temp;
                dp_score[i][j] = -1;
            }
        }

        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = 0; j < 5; j++)
            {
                if (road[i][j] != 1)
                {
                    // curr score(장애물 확인)
                    dp_score[i][j] = (i + road[i][j]);
                    if ((j > 0) && (road[i][j - 1] == 1))
                        dp_score[i][j]++;
                    if ((j < 4) && (road[i][j + 1] == 1))
                        dp_score[i][j]++;

                    // past score(전 뻗어나갈 수 있는 지점 점수 확인)
                    if (i < N - 1)
                    {
                        int past_max_scores = 0;
                        if ((j > 0) && (road[i + 1][j - 1] != 1))
                            if (dp_score[i + 1][j - 1] > past_max_scores)
                                past_max_scores = dp_score[i + 1][j - 1];

                        if (road[i + 1][j] != 1)
                            if (dp_score[i + 1][j - 1] > past_max_scores)
                                past_max_scores = dp_score[i + 1][j];

                        if ((j < 4) && (road[i + 1][j + 1] != 1))
                            if (dp_score[i + 1][j - 1] > past_max_scores)
                                past_max_scores = dp_score[i + 1][j + 1];

                        dp_score[i][j] += past_max_scores;
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++)
            if (max_score < dp_score[0][i])
                max_score = dp_score[0][i];

        cout << max_score << "\n";
    }
}