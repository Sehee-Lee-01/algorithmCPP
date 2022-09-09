#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

// X=1부터 N까지 값을 저장한다.
vector<unsigned int> answerSet;

unsigned int countCalculate(unsigned int M)
{
    if (M == 1)
        return answerSet[0];

    // M-1
    unsigned int seekMin = answerSet[(M - 1) - 1];
    if ((M % 3 == 0) && (seekMin > answerSet[(M / 3) - 1]))
        seekMin = answerSet[(M / 3) - 1];
    if ((M % 2 == 0) && (seekMin > answerSet[(M / 2) - 1]))
        seekMin = answerSet[(M / 2) - 1];
    return (1 + seekMin);
}

unsigned int makeAnswerSet(unsigned int N)
{
    answerSet.push_back(0); // X==1
    unsigned int M = 2;
    while (M <= N)
    {
        unsigned int counter = countCalculate(M);
        answerSet.push_back(counter);
        M++;
    }
    return answerSet[N - 1];
}

int main()
{
    unsigned int N, minCount;
    scanf("%d", &N);
    minCount = makeAnswerSet(N);
    printf("%d\n", minCount);

    return 0;
}