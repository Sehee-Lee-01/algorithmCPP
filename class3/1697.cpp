#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000
// 방문 중복 해결하기

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int minVistited[MAX + 1];
    bool isVistited[MAX + 1];
    for (int i = 0; i < MAX + 1; i++)
    {
        minVistited[i] = abs(N - i);
        isVistited[i] = false;
    }
    // minVistited[K] = abs(N - K);

    if ((K <= N) || (MAX < N * 2))
    {
        cout << minVistited[K] << "\n";
        return 0;
    }

    queue<vector<int>> toGo;
    toGo.push({N, 0, -1});

    while (!toGo.empty())
    {
        vector<int> curr = toGo.front();
        toGo.pop();
        // cout << "0: " << curr[0] << ", 1: " << curr[1] << ", 2:" << curr[2] << "\n";
        // cout << "minVistited[K]: " << minVistited[K] << "\n";

        if ((minVistited[K] < curr[1]) || (minVistited[curr[0]] < curr[1]) || (minVistited[curr[0]] == curr[1] && isVistited[curr[0]] == true))
            continue;
        if (K == curr[0])
        {
            minVistited[K] = curr[1];
            isVistited[K] = true;
            continue;
        }

        minVistited[curr[0]] = curr[1];
        isVistited[curr[0]] = true;

        // if (minVistited[curr[0]] == curr[1])
        // cout << curr[0] << " " << curr[1] << " " << curr[2] << "\n";

        if ((curr[0] > 0) && (curr[0] - 1 != curr[2]) && (minVistited[curr[0]] - 1 >= curr[1] + 1))
            toGo.push({curr[0] - 1, curr[1] + 1, curr[0]});

        if ((curr[0] < MAX) && (curr[0] + 1 != curr[2]) && (minVistited[curr[0]] + 1 >= curr[1] + 1))
            toGo.push({curr[0] + 1, curr[1] + 1, curr[0]});

        if (curr[0] <= MAX / 2 && (minVistited[curr[0]] * 2 >= curr[1]))
            toGo.push({curr[0] * 2, curr[1] + 1, curr[0]});
    }

    cout << minVistited[K] << "\n";
    return 0;
}

/*
1. 방문 중복을 신경을 쓰지 않았다.
2. BFS, DFS 구분을 제대로 안하고 막 풀었다.큐, 스택의 차이점을 항상 명시하자.
3. Stack을 사용해서 풀려 했다.(DFS)
4. Queue를 왜 써야할까?(Queue)
=> DFS로 가면 낭비다. 0 100 이 주어졌을 때 DFS로 하게되면 과장해서 100을 훨씬 넘는 1024에서 100까지 가는방법을 찾을 수도 있다. 중복 설정하기도 좀 까다롭다.(재귀로 한다면 할 수는 있겠지마는,,,,)
=> BFS로 하면 조금조금씩 고루고루 찾아나가기 때문에 저기 까지 갈 일은 없다. 결국 낭비는 안한다.
*/