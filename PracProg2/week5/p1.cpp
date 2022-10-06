// -
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int T, L;
    string temp;
    cin >> T;
    while (T--)
    {
        cin >> L;
        while (L--)
        {
            cin >> temp;
            cout << "temp" << T << ": " << temp << '\n';
        }
    }
}
