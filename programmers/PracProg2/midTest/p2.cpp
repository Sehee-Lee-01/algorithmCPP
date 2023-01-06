// 사다리 타기
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, d;
        cin >> n >> m >> d;
        string temp, sadari[m];
        getline(cin, temp);
        for (int i = 0; i < m; i++)
        {
            getline(cin, temp);
            sadari[m - 1 - i] = temp; // 거꾸로 받기
            // cout << temp << endl;
        }
        int currLocation = d * 2 - 2; // 목적지 위치

        for (int i = 1; i < m; i++)
        {
            // cout << sadari[i] << endl;
            // 그 앞의 이동할 수 있는 양 방향으로 이동
            if ((currLocation < n * 2 - 3) && (sadari[i][currLocation + 1] == '+'))
                currLocation += 2;
            else if ((currLocation > 1) && (sadari[i][currLocation - 1] == '+'))
                currLocation -= 2;

            // 양쪽 이동할 수 없다면 그냥 제자리
        }

        currLocation += 2;
        currLocation /= 2;
        cout << currLocation << '\n';
    }
}