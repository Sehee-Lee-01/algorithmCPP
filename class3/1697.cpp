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
    bool isVistited[MAX + 1];

    for (int i = 0; i < MAX + 1; i++)
        isVistited[i] = false;

    int minCnt = abs(N - K);

    /*아래 주석을 생략했을 때 시간이 더 빠른이유(아래 생략을 안하면 12ms, 생략하면 8ms)*/
    // if (K <= N)
    // {
    //     cout << minCnt << "\n";
    //     return 0;
    // }

    queue<vector<int>> toGo;
    toGo.push({N, 0});

    while (!toGo.empty())
    {
        vector<int> curr = toGo.front();
        toGo.pop();
        // cout << "0: " << curr[0] << ", 1: " << curr[1] << ", 2:" << curr[2] << "\n";
        // cout << "minVistited[minCnt: " << minCnt << "\n";

        if (K == curr[0])
        {
            minCnt = curr[1];
            break;
        }
        // if (minVistited[curr[0]] == curr[1])
        // cout << curr[0] << " " << curr[1] << " " << curr[2] << "\n";

        if ((curr[0] > 0) && (isVistited[curr[0] - 1] == false))
        {
            isVistited[curr[0] - 1] = true;
            toGo.push({curr[0] - 1, curr[1] + 1, curr[0]});
        }
        if ((curr[0] < MAX) && (isVistited[curr[0] + 1] == false))
        {
            isVistited[curr[0] + 1] = true;
            toGo.push({curr[0] + 1, curr[1] + 1, curr[0]});
        }
        if (curr[0] <= MAX / 2 && (isVistited[curr[0] * 2] == false))
        {
            isVistited[curr[0] * 2] = true;
            toGo.push({curr[0] * 2, curr[1] + 1, curr[0]});
        }
    }

    cout << minCnt << "\n";
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