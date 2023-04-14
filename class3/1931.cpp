#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Conference
{
    int start = -1, end = -1;
};

bool cmp(Conference a, Conference b)
{
    if (a.end != b.end)
        return a.end < b.end;
    else
        return a.start < b.start;
}

int main()
{
    int N, a, b, ableCount;
    cin >> N;

    vector<Conference> conferences(N);

    for (int i = 0; i < N; i++)
    {
        cin >> conferences[i].start >> conferences[i].end;
    }

    sort(conferences.begin(), conferences.end(), cmp);

    int recEndTime = 0, cnt = 0;

    for (int i = 0; i < N; i++)
    {
        if (conferences[i].start >= recEndTime)
        {
            cnt++;
            recEndTime = conferences[i].end;
        }
    }

    cout << cnt << "\n";
}