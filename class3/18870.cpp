#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> cors(N);
    map<int, vector<int>> maps;
    for (int i = 0; i < N; i++)
    {
        cin >> cors[i];
        if (maps.find(cors[i]) == maps.end())
            maps.insert({cors[i], {i}});
        else
            maps[cors[i]].push_back(i);
    }
    int cnt = 0;
    vector<int> res(N);
    for (auto num_map : maps)
    {
        for (int idx : num_map.second)
            res[idx] = cnt;
        cnt++;
    }

    for (int i = 0; i < N; i++)
        cout << res[i] << " ";
    cout << "\n";
    return 0;
}
