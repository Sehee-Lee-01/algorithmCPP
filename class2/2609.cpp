#include <iostream>
using namespace std;
int T, H, W, N, height, room; 
int main() {
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        scanf("%d %d %d", &H, &W, &N);
        if (N%H==0) {room = N/H; height = H;}
        else {room = (N/H)+1; height = (N%H);}
        printf("%d\n", height*100 + room);
    }
}