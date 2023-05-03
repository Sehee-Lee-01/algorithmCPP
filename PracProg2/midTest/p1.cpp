// 보물 찾기
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

char resultDirection(char pastDirec, char mapDirec)
{
    map<pair<char, char>, char> direcCombi = {
        {{'F', 'F'}, 'F'},
        {{'F', 'R'}, 'R'},
        {{'F', 'L'}, 'L'},
        {{'F', 'B'}, 'B'},
        {{'R', 'F'}, 'R'},
        {{'R', 'R'}, 'B'},
        {{'R', 'L'}, 'F'},
        {{'R', 'B'}, 'L'},
        {{'L', 'F'}, 'L'},
        {{'L', 'R'}, 'F'},
        {{'L', 'L'}, 'B'},
        {{'L', 'B'}, 'R'},
        {{'B', 'F'}, 'B'},
        {{'B', 'R'}, 'L'},
        {{'B', 'L'}, 'R'},
        {{'B', 'B'}, 'F'},
    };

    return direcCombi[{pastDirec, mapDirec}];
}

int direToInt(char direc)
{
    switch (direc)
    {
    case 'F':
        return 0;
    case 'R':
        return 1;
    case 'L':
        return 2;
    case 'B':
        return 3;
    };
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string tresureMap[n][n], temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> temp;
                tresureMap[i][j] = temp;
            }
        }

        // 시작
        // 맵이 해당 지점에서 설정했던 방향, 횟수 기록하는 거 있어야함.
        // 이동하기 직전 방향 기록하는 거 있어야함.
        vector<vector<vector<int>>> direcMap = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(4, 0))); // {F0, R0, L0, B0} 횟수 기록
        char pastDirec = 'B';
        int currY = 0, currX = 0;
        while (1)
        {
            char mapDirec = tresureMap[currY][currX][0];
            int distance = tresureMap[currY][currX][1] - '0';

            // 가야할 방향을 구하자
            pastDirec = resultDirection(pastDirec, mapDirec);
            int direInt = direToInt(pastDirec);
            // 현재 위치 방향을 확인하고(보물)
            if (direcMap[currY][currX][direInt] > 1)
            {
                cout << currY << ' ' << currX << '\n';
                break;
            }
            // 아니면 기록하고 이동하자
            else
            {
                direcMap[currY][currX][direInt]++;
                switch (pastDirec)
                {
                case 'F':
                    currY += distance;
                    break;
                case 'R':
                    currX += distance;
                    break;
                case 'L':
                    currX -= distance;
                    break;
                case 'B':
                    currY -= distance;
                    break;
                }
            }
        }
    }
}