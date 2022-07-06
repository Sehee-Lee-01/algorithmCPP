#include <iostream>
using namespace std;
int N, K, mul_up=1 ,mul_down=1;
int main() {
    scanf("%d %d", &N, &K);
    if((K!=0)&&(K!=N)) {
        for(int i=N; i>(N-K); i--) {mul_up*=i;}
        for(int i=1; i<=K; i++) {mul_down*=i;}
        printf("%d\n",mul_up/mul_down);
    }
    else {printf("1\n");}
}