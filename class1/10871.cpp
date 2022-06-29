#include <iostream>
using namespace std;
int N, X, temp;
int main() {
    scanf("%d %d",&N, &X);
    for (int i=0; i<N; i++) {
        scanf("%d", &temp);
        if(temp<X) printf("%d ",temp);
    }
}