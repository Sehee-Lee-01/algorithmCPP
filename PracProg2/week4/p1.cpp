// 사다리 타기
#include <iostream>
#include <string>
using namespace std;

int t, n, m, d;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> d;
        string temp, sadari[m];
        getline(cin, temp);
        for (int i = 0; i < m; i++)
        {
            getline(cin, temp);
            sadari[i] = temp;
            // cout << temp << "\n";
        }

        int curr_state = d, cal_state;
        while (m--)
        {
            cal_state = curr_state * 2 - 2;
            if ((curr_state > 1) && (sadari[m - 1][cal_state - 1] == '+'))
            {
                curr_state--;
                continue;
            }
            if ((curr_state < n) && (sadari[m - 1][cal_state + 1] == '+'))
            {
                curr_state++;
                continue;
            }
        }
        cout << curr_state << "\n";
    }
}