// 동적배열
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, n, a, c;
    cin >> t;
    while (t--)
    {
        // 배열 크기, 원소 개수
        unsigned int totalCopy = 0;
        vector<pair<unsigned int, unsigned int>> arrays = vector<pair<unsigned int, unsigned int>>(101, {0, 0});
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a >> c;

            if (arrays[a].first == 0) // 배열이 없었던 경우
            {
                unsigned int arraySize = 2;
                while (c >= arraySize)
                    arraySize *= 2;
                arrays[a].first = arraySize;
                arrays[a].second = c;
            }
            else // 배열이 있는 경우
            {
                if (arrays[a].second + c > arrays[a].first) // 배열 크기를 넘는 경우(복사)
                {
                    totalCopy += arrays[a].second;
                    arrays[a].second += c;
                    while (arrays[a].second >= arrays[a].first)
                        arrays[a].first *= 2;
                }
                // 아닌경우 원소 수만 추가
                else
                    arrays[a].second += c;
            }
            // cout << a << "arrays[a].first " << arrays[a].first << '\n';
        }
        cout << totalCopy << '\n';
    }
}