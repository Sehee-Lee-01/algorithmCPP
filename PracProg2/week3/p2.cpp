// 채용 시험, 이건 풀어야됨
// bfs!
// dfs는 시간초과남
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t, N, M;
    cin >> t;
    // in test case
    for (int i = 0; i < t; i++)
    {
        // scan miro
        cin >> N >> M;
        int miro[M][N], temp;
        for (int j = 0; j < M; j++)
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
        seekStack.push_back({0, 0, 1, -1, -1});
        int minLength = N * M; // 완료 최솟값과 비교하여 최솟값이면 넣기
        while (!seekStack.empty())
        {
            vector<int> currentInfo = seekStack.back();

            // debug
            // for (auto element: currentInfo) {cout << element << " ";}
            // cout << "***\n";

            seekStack.pop_back();
            int Y = currentInfo[0], X = currentInfo[1], currentLength = currentInfo[2], pastY = currentInfo[3], pastX = currentInfo[4];
            if (currentLength >= minLength)
                continue;
            // 도착일 경우 비교하기
            if ((Y == M) && (X == N))
            {
                minLength = currentLength;
                continue;
            }

            // 도착이 아닌 경우(이전 좌표와 다르고, 범위 고려하기)
            //위
            if ((Y - 1 >= 0) && (Y - 1 != pastY) && (miro[Y - 1][X] == 1))
            {
                vector<int> nextVisit = {Y - 1, X, currentLength + 1, Y, X};
                seekStack.push_back(nextVisit);
            }
            // 아래
            if ((Y + 1 <= M) && (Y + 1 != pastY) && (miro[Y + 1][X] == 1))
            {
                vector<int> nextVisit = {Y + 1, X, currentLength + 1, Y, X};
                seekStack.push_back(nextVisit);
            }
            // 왼
            if ((X - 1 >= 0) && (X - 1 != pastX) && (miro[Y][X - 1] == 1))
            {
                vector<int> nextVisit = {Y, X - 1, currentLength + 1, Y, X};
                seekStack.push_back(nextVisit);
            }
            //오른
            if ((X + 1 <= N) && (X + 1 != pastX) && (miro[Y][X + 1] == 1))
            {
                vector<int> nextVisit = {Y, X + 1, currentLength + 1, Y, X};
                seekStack.push_back(nextVisit);
            }
        }

        cout << minLength << "\n";
    }
}