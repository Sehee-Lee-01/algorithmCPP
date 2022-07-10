#include <iostream>
#include <set>
using namespace std;

int N, temp;
set<int> sortlist;
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &temp);
        sortlist.insert(temp);
    }
    for(auto &c : sortlist) {
        printf("%d\n", c);
    }
}