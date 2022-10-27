// 보물찾기
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int changeDirecToNum(const char Direction)
{
    if (Direction == 'F')
        return 0;
    else if (Direction == 'R')
        return 1;
    else if (Direction == 'L')
        return 2;
    else
        return 3;
}

const char findDirection(const char pastDirecction, const char currentDirection)
{
    pair<char, char> directionPair = {pastDirecction, currentDirection};
    map<pair<char, char>, char> directionMap = {
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

    return directionMap[directionPair];
}

int main()
{
    int t, n;
    cin >> t;
    string ab;
    while (t--)
    {
        cin >> n;
        vector<vector<string>> treasureMap(n, vector<string>(n));
        // count {F, R, L, B}
        vector<vector<vector<int>>> moveLog(n, vector<vector<int>>(n, vector<int>(4)));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ab;
                treasureMap[i][j] = ab;
            }
        }

        int currY = 0, currX = 0;
        char pastDirection = 'B';
        while (1)
        {
            // 현재 방향과 이동한 좌표 저장된 방향을 구하고 리턴
            char mapDirection = treasureMap[currY][currX][0];
            pastDirection = findDirection(pastDirection, mapDirection);
            int distance = treasureMap[currY][currX][1] - '0';
            // cout << distance << ' ' << currX << '\n';

            // 리턴한 방향을 기록하고 거리만큼 이동(pastDirection, currCoordinate 변경해주기)
            moveLog[currY][currX][changeDirecToNum(pastDirection)]++;
            //보물 찾음
            if (moveLog[currY][currX][changeDirecToNum(pastDirection)] > 1)
            {
                cout << currY << ' ' << currX << '\n';
                break;
            }
            else
            {
                switch (pastDirection)
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