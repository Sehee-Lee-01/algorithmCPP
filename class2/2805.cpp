#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M, height, height_start, height_end, mid, sum, ans;
vector<unsigned int> trees;

int main() {
    // input
    scanf("%d %d\n", &N, &M);
    for (int i=0; i<N; i++) {
        scanf("%d", &height);
        trees.push_back(height);
    }
    // sort(desc)
    sort(trees.rbegin(), trees.rend());
    
    // binary search
    height_start = 0; height_end = trees[0];
    while (height_start<=height_end) {
        // 
        mid = (height_start+height_end)/2;
        
        // calculate sum
        sum=0;
        for(auto &tree : trees) {
            long long sub = tree-mid;
            if (sub>0){sum+=sub;} else {break;}
        }
        // printf("uu%d\n", sum);
        if (sum<M) {height_end = mid-1;}
        else {
            height_start = mid+1; 
            if(ans<mid) {
                ans=mid;
            }
        }
    }
    printf("%d\n", ans);
}