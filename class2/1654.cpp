#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int K, N, X, limit_X = 1, temp, lan_count;

int main() {
    scanf("%d %d", &K, &N);
    vector<int> lan_length;
    for (int i=0; i<K; i++) {
        scanf("%d", &temp);
        lan_length.push_back(temp);
    }
    sort(lan_length.begin(), lan_length.end());
    X = lan_length.back();
    while (1)
    {
        temp = (X+limit_X)/2;
        lan_count = 0;
        for (auto iter=lan_length.begin(); iter!=lan_length.end();iter++) {lan_count += *iter/temp;}
        if (X < limit_X) {break;}
        else if(lan_count<N) {X = temp-1;} 
        else{limit_X = temp+1;}
    }
    
    printf("%d\n", X);
}