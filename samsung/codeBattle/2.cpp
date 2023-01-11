#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        string N;
        int small, big;
        cin >> N >> small >> big;

        string res = "";
        int loc = 0;

        while (loc < N.size())
        {
            if ((N[loc] - '0') > big)
                break;
            else if ((N[loc] - '0') == big)
            {
                if ((loc + 1 < N.size()) && (N[loc + 1] - '0' < small)) // 다음 수 확인
                {
                    res += (small + '0');
                    loc++;
                    break;
                }

                res += (big + '0'); // 게속 이어짐
            }
            else if ((N[loc] - '0') > small)
            {
                res += (small + '0');
                loc++;
                break;
            }
            else if ((N[loc] - '0') == small)
            {
                if ((loc + 1 < N.size()) && (N[loc + 1] - '0' < small)) // 다음 수 확인
                {
                    int big_idx = -1;
                    for (int i = (res.size() - 1); i >= 0; i--)
                    {
                        if (res[i] == big + '0')
                        {
                            big_idx = i;
                            break;
                        }
                    }

                    if (big_idx >= 0)
                    {
                        string temp = "";
                        for (int j = 0; j < big_idx; j++)
                            temp += res[j];
                        temp += small + '0'; // big_idx
                        res = temp;
                        loc = big_idx + 1;
                    }
                    else
                    {
                        res = "";
                        loc = 1;
                    }
                    break;
                }

                res += (small + '0'); // 게속 이어짐
            }
            else // 맨 처음 수가 small 보다 작은 경우만 해당됨
            {
                loc++;
                break;
            }

            loc++;
        }

        // res += '+';

        for (int i = 0; i < (N.size() - loc); i++)
            res += (big + '0');

        if (res != "" && res != "0")
        {
            while (res[0] == '0')
                res.erase(0, 1);
            cout << "#" << test_case << " " << res << "\n";
        }
        else
            cout << "#" << test_case << " -1\n";
    }
    return 0;
}