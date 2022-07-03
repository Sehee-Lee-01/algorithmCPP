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
    temp = K-1;
    while (1) {
        X = lan_length[temp]; 
        lan_count = 0;
        for (auto iter=lan_length.begin(); iter!=lan_length.end();iter++) {lan_count += *iter/X;}
        if ((lan_count<N)&&(temp!=0)) {temp--;} else {break;}
    }
    
    while (1)
    {
        temp = (X+limit_X)/2;
        lan_count = 0;
        for (auto iter=lan_length.begin(); iter!=lan_length.end();iter++) {lan_count += *iter/temp;}
        if(lan_count<N) {X = temp;} else {limit_X = temp;}
        if((limit_X-1 == X)||(limit_X == X-1)||(limit_X == X)) {break;}
        // cout << "X: "<<X << " limit_X: "<<limit_X << endl;
    }

    // printf("X: %d, lan_count: %d\n", X, lan_count);
    if (limit_X>X) {printf("%d\n", X);}
    else {printf("%d\n", limit_X);}
}