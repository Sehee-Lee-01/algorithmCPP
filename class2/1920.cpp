#include <iostream>
#include <set>
using namespace std;

int N, temp, M;
set<int> A;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) { scanf("%d", &temp); A.insert(temp); }
    
    scanf("%d", &M); 
    for (int i=0; i<M; i++) { 
        scanf("%d", &temp); 
        if (A.find(temp)==A.end()) {printf("0\n");}
        else {printf("1\n");}
    }
}