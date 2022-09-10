#include <iostream>
#include <vector>
using namespace std;

// init
vector<int> countList;
void setCountList(int maxN)
{
    countList.push_back(0); // init
    countList.push_back(1); // 1 = 1
    countList.push_back(2); // 2 = 1 + 1 = 2
    countList.push_back(4); // 3 = 1 + 1 + 1 = 2 + 1  = 1 + 2 = 3
    for (int i = 4; i < maxN + 1; i++)
    {
        int count123 = 0;
        if (i - 1 > 0)
            count123 += countList[i - 1];
        if (i - 2 > 0)
            count123 += countList[i - 2];
        if (i - 3 > 0)
            count123 += countList[i - 3];

        // push
        countList.push_back(count123);
    }
}

int main()
{
    int T, n, maxN = 0;
    vector<int> nList;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        nList.push_back(n);
        if (maxN < n)
            maxN = n;
    }
    setCountList(maxN);
    for (auto element : nList)
        printf("%d\n", countList[element]);
}