#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, temp, n, good_start=1, good_end, ans=0;

vector<int> set_s;

int main() {
    scanf("%d", &L);
    for(int i=0; i<L; i++) {
        scanf("%d", &temp);
        set_s.push_back(temp);
    }
    sort(set_s.begin(),set_s.end());

    scanf("%d", &n);
    for(auto iter=set_s.begin(); iter!=set_s.end(); iter++) {
        if(*iter == n) {break;}
        if(*iter < n) {good_start = *iter+1;}
        if(*iter > n) {good_end = *iter-1; break;}
    }
    for (int i=good_start; i<=n; i++) {
        for(int j=n; j<=good_end; j++) {
            if(i == j) continue;
            ans++;
        }
    }
    printf("%d\n", ans);
}