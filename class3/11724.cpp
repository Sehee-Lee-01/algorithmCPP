#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M, u, v;
    cin >> N >> M;

    vector<int> links[N + 1];
    bool visited[N + 1];

    for (int i = 0; i < N + 1; i++)
        visited[i] = false;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        links[u].push_back(v);
        links[v].push_back(u);
    }

    int linkCnt = 0;
    for (int i = 1; i < N + 1; i++)
    {
        vector<int> toVisit;
        if (!visited[i])
        {
            toVisit.push_back(i);
            visited[i] = true;
            while (!toVisit.empty())
            {
                int curr = toVisit.back();
                toVisit.pop_back();
                for (auto node : links[curr])
                    if (!visited[node])
                    {
                        toVisit.push_back(node);
                        visited[node] = true;
                    }
            }
            linkCnt++;
        }
    }

    cout << linkCnt << "\n";
}