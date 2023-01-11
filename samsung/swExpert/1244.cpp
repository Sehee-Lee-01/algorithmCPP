// 재귀
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int num, cnt;
        cin >> num >> cnt;

        string strSort = to_string(num), str = strSort;
        sort(strSort.begin(), strSort.end(), greater());
        int max = strSort[0];
        vector<int> vals[max + 1];

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != strSort[i])
                vals[str[i]].push_back[i];
        }

        int max_val = max, st = 0;
        while (max_val && cnt)
        {
            if (!vals[max_val].empty())
            {
                int chgMax = vals[max_val].size();
                if (chgMax > cnt)
                    chgMax = cnt;

                vector<int> toChg;
                // 최댓값으로 바꿔야하는 횟수만큼 바꾸기
                while (chgMax)
                {
                    if (str[st] < max_val)
                    {
                        toChg.push_back(str[i]);
                        str[st] = max_val;
                        chgMax--;
                    }
                    st++;
                }
                sort(toChg.begin(), toChg.end());

                cnt = chgMax;
            }
            max_val--;
        }

        cout << "#" << test_case << " " << inToSt << "\n";
    }

    return 0;
}