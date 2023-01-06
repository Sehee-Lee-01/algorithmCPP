#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int main()
{
    int t, n, m, temp;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        // 최대 전시 가능 개수 n개 지키기
        vector<vector<int>> junsi;
        for (int j = 0; j < m; j++)
        {
            // 게시판에 걸린 작품 하나당 가져야하는 정보
            // 번호, 추천 수, 오래된 순
            cin >> temp;
            bool isin = false;
            int to_out_idx = -1, min = m, min_time = m;
            // 존재부터 확인하면서 오래된 거, 추천 수 적은 거 찾기
            for (int k = 0; k < junsi.size(); k++)
            {
                if (junsi[k][0] == temp) // 이미 전시된거면 추천 수 증가
                {
                    junsi[k][1]++;
                    isin = true;
                }
                if ((junsi[k][1] < min) || ((junsi[k][1] == min) && (junsi[k][2] < min_time)))
                {
                    to_out_idx = k;
                    min = junsi[k][1];
                    min_time = junsi[k][2];
                }
            }
            if (!isin) // 새로운 거면 반드시 추가 하고 기준에 부합하는 거 뺀다.
            {
                if (junsi.size() == n) // 전시 가능 개수가 딱 차는 경우
                    junsi.erase(junsi.begin() + to_out_idx);
                // cout << "test\n";
                junsi.push_back({temp, 1, j});
            }
        }

        sort(junsi.begin(), junsi.end(), cmp);
        for (int j = 0; j < junsi.size(); j++)
        {
            cout << junsi[j][0] << " ";
        }
        cout << "\n";
    }
}