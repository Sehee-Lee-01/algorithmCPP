#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t, n, a;
    cin >> t;
    while (t--)
    {
        cin >> n >> a;
        string input_line;
        vector<string> origin;
        for (int i = 0; i < n; i++)
        {
            cin >> input_line;
            origin.push_back(input_line);
            // cout << "test" << '\n';
        }
        for (int i = 0; i < n; i++)
        {
            if (a == 0) // 원래와 비슷
                cout << origin[i] << '\n';

            else if ((a == 180) || (a == -180)) // 거꾸로
            {
                for (int j = n - 1; j >= 0; j--)
                    cout << origin[n - 1 - i][j];
                cout << '\n';
            }
            else if ((a == 90) || (a == -270))
            {
                // 시작점 origin[n-1][0]
                for (int j = 0; j < n; j++)
                    cout << origin[n - 1 - j][i];
                cout << '\n';
            }
            else if ((a == 270) || (a == -90))
            {
                // 시작점 origin[0][n-1]
                for (int j = 0; j < n; j++)
                    cout << origin[j][n - 1 - i];
                cout << '\n';
            }
        }
    }
}