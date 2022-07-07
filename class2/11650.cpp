#include <iostream>
#include <map>
#include <set>
using namespace std;

int N, x, y;
map<int, set<int>> input;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &x, &y);
        auto iter = input.find(x);
        if (iter != input.end()) {iter->second.insert(y);}
        else {
            set<int> new_set; new_set.insert(y);
            input.insert({x, new_set});
        }
    }
    for (auto &i : input) {
        for(auto &j : i.second) {
            printf("%d %d\n", i.first, j);
        }
    }
}