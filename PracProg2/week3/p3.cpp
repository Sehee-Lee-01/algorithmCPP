// 택배배송
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, A, B;
        scanf("%d %d %d %d", &n, &m, &A, &B);
        int cross_weight[n + 1][n + 1]; // -1 초기화
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < n + 1; j++)
                cross_weight[i][j] = -1;

        int log[n + 1];
        for (int i = 0; i < n + 1; i++)
            log[i] = 0;

        vector<pair<int, int>> cities[n + 1];

        int O, D, C;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &O, &D, &C);
            if ((!cross_weight[O][D]) || (C > cross_weight[O][D]))
            {
                cross_weight[O][D] = C;
                cross_weight[D][O] = C;
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if ((i != j) && (cross_weight[i][j]))
                    cities[i].push_back(make_pair(j, cross_weight[i][j]));

        priority_queue<vector<int>> to_visit;
        vector<int> start = {10001, -1, A};
        to_visit.emplace(start);

        while (!to_visit.empty())
        {
            vector<int> curr_info = to_visit.top();
            to_visit.pop();

            if (curr_info[0] <= log[curr_info[2]])
                continue;

            log[curr_info[2]] = curr_info[0];

            if (curr_info[2] == B)
                break;

            for (auto it = cities[curr_info[2]].begin(); it != cities[curr_info[2]].end(); it++)
            {
                int next_node = it->first, next_weight = it->second;
                if (next_node == curr_info[1])
                    continue;
                if ((log[next_node] < curr_info[0]) && (curr_info[0] <= next_weight))
                {
                    vector<int> next_info = {curr_info[0], curr_info[2], next_node};
                    to_visit.emplace(next_info);
                    continue;
                }
                if ((log[next_node] < next_weight) && (curr_info[0] > next_weight))
                {
                    vector<int> next_info = {next_weight, curr_info[2], next_node};
                    to_visit.emplace(next_info);
                }
            }
        }
        printf("%d\n", log[B]);
    }
}