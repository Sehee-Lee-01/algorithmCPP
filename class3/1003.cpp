#include <iostream>
#include <vector>
using namespace std;

// N=0 (1, 0), N=1 (0, 1), N=2 (1, 1)
// N=3 (1, 2), N=4 (2, 3)...
// N=t ((t-1)[0]+(t-2)[0], (t-1)[0]+(t-2)[0])

vector<pair<int, int>> answerSet;
// make tuple vector
void makeAnswerSet()
{
    // init
    answerSet.push_back({1, 0});
    answerSet.push_back({0, 1});
    for (int i = 2; i <= 40; i++)
    {
        int getZero = answerSet[i - 1].first + answerSet[i - 2].first;
        int getOne = answerSet[i - 1].second + answerSet[i - 2].second;
        answerSet.push_back({getZero, getOne});
    }
}

int main()
{
    // init
    makeAnswerSet();

    int testcase, temp;
    scanf("%d", &testcase);
    for (int i = 0; i < testcase; i++)
    {
        scanf("%d", &temp);
        printf("%d %d\n", answerSet[temp].first, answerSet[temp].second);
    }
}