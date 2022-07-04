#include <iostream>
using namespace std;
int M, N, curr;
bool is_so; 
int main() {
    scanf("%d %d", &M, &N);
    bool is_so[N+1]; is_so[0]=false; is_so[1]=false;
    for (int i=2; i<=N; i++) {is_so[i]=true;}
    for (int i=2;i<=N;i++){
        int n = 2;
        while ((i*n)<=N){is_so[i*n++]=false;}
    }
    for (int i=M; i<=N; i++) {if(is_so[i]) {printf("%d\n", i);}}
}