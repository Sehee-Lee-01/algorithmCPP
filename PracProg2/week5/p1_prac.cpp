// -
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int T, L;
    cin >> T;
    while (T--)
    {
        cin >> L;
        vector<string> cals;
        vector<ll> nums;
        while (L-- > 0)
        {
            string temp;
            cin >> temp;

            // 괄호랑 곱하기 먼저 처리하기
            if (temp == ")")
            {
                vector<string> sub_cals;
                vector<ll> sub_nums;
                sub_nums.push_back(nums.back());
                nums.pop_back();
                while (cals.back() != "(")
                {
                    string curr_cal = cals.back();
                    cals.pop_back();
                    sub_cals.push_back(curr_cal);
                    sub_nums.push_back(nums.back());
                    nums.pop_back();
                }
                cals.pop_back(); // "(" 지우기

                ll brace_result = sub_nums.back();
                sub_nums.pop_back();

                while (!sub_cals.empty())
                {
                    string curr_cal = sub_cals.back();
                    sub_cals.pop_back();
                    ll temp = sub_nums.back();
                    sub_nums.pop_back();
                    brace_result += temp;
                }
                // cout << "cals.empty(): " << cals.empty() << endl;

                if (!cals.empty())
                {
                    string front_cal = cals.back();

                    if (front_cal == "*")
                    {
                        cals.pop_back();
                        ll front_num = nums.back();
                        nums.pop_back();
                        brace_result *= front_num;
                    }

                    else if (front_cal == "-")
                        brace_result = -brace_result;
                }

                nums.push_back(brace_result);
                // cout << "brace_result " << brace_result << endl;

                continue;
            }

            if (temp == "*")
            {
                cin >> temp;
                L--;

                if (temp == "(")
                {
                    cals.push_back("*");
                    cals.push_back(temp);
                }
                else
                {
                    ll result = nums.back() * stoi(temp);
                    nums.pop_back();
                    nums.push_back(result);
                }
                continue;
            }

            if (temp == "-")
            {
                cin >> temp;
                L--;
                if (temp == "(")
                {
                    cals.push_back("-");
                    cals.push_back(temp);
                }
                else
                {
                    ll result = nums.back() - stoi(temp);
                    nums.pop_back();
                    nums.push_back(result);
                }
                continue;
            }

            if ((temp == "+") || (temp == "("))
            {
                cals.push_back(temp);
                continue;
            }

            nums.push_back(stoi(temp));
        }

        // 스택에 쌓인 +- 처리하기

        ll final_result = nums.back();

        nums.pop_back();

        while (!cals.empty())
        {
            string curr_cal = cals.back();
            cals.pop_back();
            ll temp = nums.back();
            nums.pop_back();
            final_result += temp;
        }
        nums.push_back(final_result);
        // 결과 출력
        cout << nums.back() << '\n';
    }
}
