#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, x, y;
vector<pair<int,int>> dungchi;
vector<int> small_count;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &x, &y);
       dungchi.push_back({x, y});
    }    
    
    for (auto element: dungchi) {
        int count=0;
        for (auto diff_element: dungchi) {
            if((element.first<diff_element.first)&&(element.second<diff_element.second)) {count++;}
        }
        small_count.push_back(count);
    }

    for (auto element: small_count) {printf("%d ", element+1);}
    printf("\n");
}