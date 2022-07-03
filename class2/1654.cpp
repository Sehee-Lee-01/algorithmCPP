#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

unsigned int K, N, X, temp, lan_count, limit_X = 1;

int main() {
    scanf("%d %d", &K, &N);
    vector<unsigned int> lan_length;
    for (int i=0; i<K; i++) {
        scanf("%d", &temp);
        lan_length.push_back(temp);
    }
    sort(lan_length.begin(), lan_length.end());
    X = lan_length.back();
    while (limit_X <= X)
    {
        temp = (X+limit_X)/2;
        // printf("lan count %d limit_X %d X %d temp(mid) %d\n", lan_count, limit_X, X, temp);
        lan_count = 0;
        for (auto iter=lan_length.begin(); iter!=lan_length.end();iter++) {lan_count += *iter/temp;}
        
        if(lan_count<N) {X = temp-1;} 
        else {limit_X = temp+1;}
    }

    printf("%d\n", X);
}