// 직원 테스트
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t, n, m;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        string real_pw, secu_pw;
        cin >> real_pw >> secu_pw;
        int isin = 0;
        for (int i = 0; i < secu_pw.length(); i++)
        {
            if (secu_pw[i] = real_pw[0])
            {
                int index = 0;
                while ((index < real_pw.length()) && (index + i < secu_pw.length()) && (secu_pw[index + i] == real_pw[index]))
                    index++;

                if (index == real_pw.length())
                {
                    cout << 1 << "\n";
                    isin = 1;
                    break;
                }
                else
                    continue;
            }
        }
        if (!isin)
            cout << 0 << "\n";
    }
}