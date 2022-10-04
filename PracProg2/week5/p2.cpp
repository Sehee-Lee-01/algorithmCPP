#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

int main()
{
    ull t, d, temp, run1, run2, income = 0;
    vector<ull> stock_price;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &d);
        run1 = d, run2 = d;
        while (run1--)
        {
            scanf("%d", &temp);
            stock_price.push_back(temp);
        }
        while (run2--)
        {
            if (run2 > 1)
            {
                // 마지막은 바로 앞 거 높은지 보기
                if (stock_price[run2 - 1] > stock_price[run2 - 2])
                {
                    curr_max = stock_price[run2 - 1];
                }
            }
        }
    }
}