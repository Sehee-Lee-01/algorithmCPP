#include <iostream>
#include <map>
using namespace std;

int N, M, temp;
map<int,int> input;
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d",&temp);
        auto find_iter = input.find(temp);
        if(find_iter==input.end()) {input.insert({temp,1});}
        else {find_iter->second++;}
    }
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        scanf("%d", &temp);
        auto find_iter = input.find(temp);
        if(find_iter==input.end()){printf("0 ");}
        else{printf("%d ", find_iter->second);}
    }
}