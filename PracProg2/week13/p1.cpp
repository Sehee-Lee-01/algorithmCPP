#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp1(vector<int> a, vector<int> b)
{
    if (a[2] < b[2])
        return false;
    else if (a[2] > b[2])
        return true;
    else
        return a[3] < b[3];
}
bool cmp2(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        // 작품 번호, 추천 수, 전시된 시간
        vector<vector<int>> piece_list;
        int temp;
        for (int i = 0; i < m; i++)
        {
            cin >> temp;
            int isInIndex = -1; // 일단 있는지 확인하면서 시간 증가
            for (int i = 0; i < piece_list.size(); i++)
            {
                piece_list[i][2]++;
                if (temp == piece_list[i][0])
                {
                    isInIndex = i;
                    break;
                }
            }

            if (isInIndex == -1) // 없다면
            {
                if (piece_list.size() == n) // 이미 자리가 찼다면
                {
                    int min_index = -1;
                    int min_rec = m + 1;
                    int min_max_time = -1;
                    for (int j = 0; j < piece_list.size(); j++)
                    {
                        if (piece_list[j][1] < min_rec)
                        {
                            min_index = j;
                            min_rec = piece_list[j][1];
                            min_max_time = piece_list[j][2];
                        }
                        else if ((piece_list[j][1] == min_rec) && (piece_list[j][2] > min_max_time))
                        {
                            min_index = j;
                            min_max_time = piece_list[j][2];
                        }
                    }
                    piece_list.erase(piece_list.begin() + min_index); // 있는 거 빼고
                }
                piece_list.push_back({temp, 1, 0});
            }
            else // 있다면 업데이트(추천 수)
                piece_list[isInIndex][1]++;
        }

        sort(piece_list.begin(), piece_list.end(), cmp2);
        for (int j = 0; j < piece_list.size(); j++)
        {
            cout << piece_list[j][0] << " ";
        }
        cout << "\n";
    }
}