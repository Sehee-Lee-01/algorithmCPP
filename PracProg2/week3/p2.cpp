// 미로탐색(채용 시험, 이건 풀어야됨)
// bfs로! dfs는 시간초과남
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int seek_x[4] = {0, 0, 1, -1}, seek_y[4] = {1, -1, 0, 0};

int main()
{
    int t, N, M;
    cin >> t;
    // in test case
    for (int i = 0; i < t; i++)
    {
        // scan miro
        cin >> N >> M;
        int miro[N][M], temp;
        for (int j = 0; j < N; j++)
        {
            // readline
            string input;
            cin >> input;
            for (int k = 0; k < input.length(); k++)
            {
                int temp = input[k] - '0';
                miro[j][k] = temp;
            }
        }
        // seek min length, start = {0,0}, end = {M, N};
        // stack 탐색ing, 완료
        vector<vector<int>> seekStack; // int stack (현재 M, 현재 y, 0.0로부터의 거리, 이전 M, 이전 y)
        seekStack.push_back({0, 0, 1, 0, 0});
        int minLength = N * M; // 완료 최솟값과 비교하여 최솟값이면 넣기
        while (!seekStack.empty())
        {
            vector<int> currentInfo = seekStack.back();
            seekStack.pop_back();
            int Y = currentInfo[0], X = currentInfo[1], currentLength = currentInfo[2], pastY = currentInfo[3], pastX = currentInfo[4];

            // // debug
            // for (auto element : currentInfo)
            // {
            //     cout << element << " ";
            // }
            // cout << "***\n";

            // 현재 거리가 최소 거리와 비슷할 경우 넘어가기
            if (currentLength <= minLength)
            {
                // 1. 도착일 경우 비교하기, 최소 이동거리 넘지 않기
                if ((Y == N - 1) && (X == M - 1))
                {
                    minLength = currentLength;
                    continue;
                }
                // 2. 도착이 아닌 경우(이전 좌표와 다르고, 범위 고려하기)
                for (int k = 0; k < 4; k++)
                {
                    int to_seek_y = Y + seek_y[k], to_seek_x = X + seek_x[k];
                    int move_length = currentLength + 1;
                    // 2-1. 범위에 들어가고
                    if ((0 <= to_seek_y) && (to_seek_y <= N) && (0 <= to_seek_x) && (to_seek_x <= M))
                    {
                        if (miro[to_seek_y][to_seek_x] == 1)
                        {
                            // 2-2. 이전 좌표와 다르면 바로 찾아간다.
                            if (((to_seek_y != pastY) || (to_seek_x != pastX)))
                            {
                                vector<int> nextVisit = {to_seek_y, to_seek_x, move_length, Y, X};
                                seekStack.push_back(nextVisit);
                            }
                        }
                    }
                }
            }
        }

        cout << minLength << "\n";
    }
}