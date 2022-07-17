#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, X, Y;
map<int, vector<int>> coordinate;

int main() {
    scanf("%d\n", &N);
    for (int i=0;i<N;i++) {
        scanf("%d %d", &X, &Y);
        auto find_Y = coordinate.find(Y);
        vector<int> X_vec; X_vec.push_back(X);
        if (find_Y == coordinate.end()) {coordinate.insert({Y,X_vec});}
        else {find_Y->second.push_back(X);}
    }
    for (auto Y_map: coordinate) {
        sort(Y_map.second.begin(),Y_map.second.end());
        for (auto X_element : Y_map.second) {
            printf("%d %d\n", X_element, Y_map.first);
        }
    }
}