#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int computerCount, connectionCount, pair1, pair2;
    scanf("%d\n%d", &computerCount, &connectionCount);
    vector<int> computerPairs[computerCount + 1];

    // make pair set
    for (int i = 0; i < connectionCount; i++)
    {
        scanf("%d %d", &pair1, &pair2);
        computerPairs[pair1].push_back(pair2);
        computerPairs[pair2].push_back(pair1);
    }

    // seek form computer 1 to anothers
    bool computerVisit[computerCount + 1];
    // make visit list
    for (int i = 0; i < computerCount; i++)
        computerVisit[i] = false;

    vector<int> toVisit;
    int virusComputer = 0;
    toVisit.push_back(1);
    computerVisit[1] = true;

    while (!toVisit.empty())
    {
        // pop visited computer
        int currentComputer = toVisit.back();
        toVisit.pop_back();

        if (currentComputer != 1)
            virusComputer++;

        for (auto element : computerPairs[currentComputer])
            if (!computerVisit[element])
            {
                computerVisit[element] = true;
                toVisit.push_back(element);
            }
    }

    // print answer
    printf("%d\n", virusComputer);
}