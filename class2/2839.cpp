#include <iostream>
using namespace std;

int N, sugar_remain, bag, minbag=5000, max5; 
int main() {
    scanf("%d",&N);
    if ((N==3)&&(N==5)) {printf("1\n"); return 0;}
    if (N==4) {printf("-1\n"); return 0;}
    sugar_remain = N;
    max5 = N/5; 
    for (int i=max5; i>=0; i--) {
        int bag=i;
        sugar_remain=N-i*5;
        if (sugar_remain%3==0) {
            bag+=sugar_remain/3;
            if (minbag > bag) minbag = bag;
        }
    }

    if(minbag!=5000) {printf("%d\n", minbag);}
    else {printf("-1\n");}
}