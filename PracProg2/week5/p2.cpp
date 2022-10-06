#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll d, run1, run2, temp, income = 0;
        vector<ll> stock_price;
        cin >> d;
        run1 = d, run2 = d;
        while (run1--)
        {
            cin >> temp;
            stock_price.push_back(temp);
        }

        ll max_price = stock_price[stock_price.size() - 1];

        while (run2--)
        {
            if (max_price < stock_price[run2])
                max_price = stock_price[run2];
            else
                income += (max_price - stock_price[run2]);
        }
        cout << income << '\n';
    }
}