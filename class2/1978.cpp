#include <iostream>
using namespace std;
bool so_su[1001]; 
int N, temp, sum;
int main() {
    // so_su[0]=false;so_su[1]=false;
    for(int i=2; i<1001; i++){so_su[i] = true;}
    for (int i=2; i<501; i++) {
        int mul = 2;
        while ((mul*i)<1001){so_su[mul++*i] = false;}
    }
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &temp);
        if (so_su[temp]) {sum++;}
    }
    printf("%d", sum);
}