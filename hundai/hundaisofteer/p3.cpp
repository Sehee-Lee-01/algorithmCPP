// 말판 게임
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n, jump_n;
    cin >> n >> jump_n;
    vector<int> map = vector<int>(n, 0);
    vector<int> jump_info;
    for (int i = 0; i < jump_n; i++)
    {
        int from_j, to_j;
        cin >> from_j >> to_j;
        if (from_j > to_j) // 더 뒤로 갈 경우
        {
            map[from_j]--;
        }
        else
        {
            map[from_j] = to_j; // 점프 가능한 곳은 점프할 인덱스 저장
        }
    }

    return 0;
}