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
        string temp;
        while (L-- > 0)
        {
            cin >> temp;
            if (temp == ")")
            {
                // 괄호 안의 마지막 문자
                ll back_num = nums.back();
                nums.pop_back();

                // 괄호 안의 마지막 연산자
                string back_cal = cals.back();
                cals.pop_back();

                // 괄호 안의 계산 결과
                ll result_brace = back_num;

                while (back_cal != "(") // 괄호를 거꾸로 끝까지 볼 때까지
                {
                    back_num = nums.back();
                    nums.pop_back();

                    result_brace += back_num; // 계속 더해나감

                    back_cal = cals.back();
                    cals.pop_back();
                }

                // 괄호 안의 계산결과가 숫자로 변환되면 괄호 앞 부호 체크
                // cout << cals.empty() << "\n";
                if (!(cals.empty()))
                {
                    if (cals.back() == "*") // 앞 숫자와 계산 후 넣기
                    {
                        cals.pop_back();
                        ll front_brace_num = nums.back();
                        nums.pop_back();
                        result_brace *= front_brace_num;
                    }
                    else if (cals.back() == "-") // + 변환 후 넣기
                    {
                        cals.pop_back();
                        cals.push_back("+");
                        result_brace *= (-1);
                    }
                }
                nums.push_back(result_brace);
                continue;
            }
            if (temp == "*")
            {
                cin >> temp;
                L--;
                if (temp == "(") // 괄호에 붙었을 때
                {
                    cals.push_back("*");
                    cals.push_back("(");
                }
                else // 다음이 숫자일 때
                {
                    ll front_num = nums.back();
                    nums.pop_back();
                    ll mul_result = front_num * stoi(temp);
                    nums.push_back(mul_result);
                }
                continue;
            }
            if (temp == "-")
            {
                cin >> temp;
                L--;
                if (temp == "(") // 괄호에 붙었을 때
                {
                    cals.push_back("-");
                    cals.push_back("(");
                }
                else // 다음이 숫자일 때
                {
                    cals.push_back("+");
                    ll num_temp = stoi(temp) * (-1);
                    nums.push_back(num_temp);
                }
                continue;
            }
            if ((temp == "+") || (temp == "("))
            {
                cals.push_back(temp);
                continue;
            }
            // temp가 숫자일 때
            nums.push_back(stoi(temp));
        }

        ll result = nums.back();
        nums.pop_back();

        if (!nums.empty())
        {
            while (!nums.empty())
            {
                result += nums.back();
                nums.pop_back();
            }
        }

        cout << result << "\n";
    }
}
