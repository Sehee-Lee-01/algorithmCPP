#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, height, sum, height_start, height_end, mid;

vector<int> trees;

bool cmp (int a, int b) {return a > b;}

int main() {
    scanf("%d %d\n", &N, &M);
    for (int i=0; i<N; i++) {
        scanf("%d", &height);
        trees.push_back(height);
    }
    
    sort(trees.begin(), trees.end(), cmp);
    height_start = 0; height_end = trees[0];
    
    while (height_start <= height_end) 
    {
        mid = (height_start + height_end)/2;
        sum = 0;
        for (auto &tree: trees) {
            int sub = tree - mid;
            if (sub>0) {sum += sub;} else {break;}
        }
        // printf("%d %d %d : %d\n", height_start, mid, height_end, sum);
        if (sum>M) {height_start = mid+1;} 
        if (sum<M) {height_end = mid-1;}
        if (sum==M) {break;}
    }
    if (sum>M) {printf("%d\n", height_end);}
    if (sum<M) {printf("%d\n", height_start);}
    if (sum==M) {printf("%d\n", mid);}
}