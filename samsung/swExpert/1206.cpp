#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    for (int test_case = 0; test_case < 10; test_case++)
    {
        int n;
        cin >> n;

        int a[n], sum = 0;
        vector<int> jomang_can, jomang;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if ((i > 1) && (a[i - 2] < a[i]) && (a[i - 1] < a[i]))
                jomang_can.push_back(i);
        }
        for (auto i : jomang_can)
        {
            if ((a[i] > a[i + 1]) && (a[i] > a[i + 2]))
                jomang.push_back(i);
        }
        for (auto i : jomang)
        {
            vector<int> temp = {a[i - 1], a[i - 2], a[i + 1], a[i + 2]};
            sum += a[i] - *max_element(temp.begin(), temp.end());
        }
        cout << "#" << test_case + 1 << " " << sum << "\n";
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}
