#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, C;
    cin >> N >> C;
    vector<int> home_loc(N, 0);
    for (int i = 0; i < N; i++)
        cin >> home_loc[i];

    sort(home_loc.begin(), home_loc.end());

    int st = 1, ed = home_loc[N - 1] - home_loc[0], mid = (st + ed) / 2;

    while (st <= ed)
    {
        int remain_rou = C - 1;
        int rec_rou = 0;
        for (int i = 1; i < N; i++)
        {
            if (home_loc[i] - home_loc[rec_rou] >= mid)
            {
                rec_rou = i;
                // cout << "home_loc[rec_rou]: " << home_loc[rec_rou] << "\n";
                remain_rou--;
            }

            if (remain_rou < 0)
                break;
        }

        if (remain_rou > 0)
            ed = mid - 1;

        else if (remain_rou <= 0)
            st = mid + 1;

        mid = (st + ed) / 2;
        cout << "remain_rou: " << remain_rou << "\n";
        // cout << "st: " << st << ", ed: " << ed << ", mid: " << mid << "\n";
    }
    // cout << "st: " << st << ", ed: " << ed << ", mid: " << mid << "\n";

    cout << mid;
    return 0;
}