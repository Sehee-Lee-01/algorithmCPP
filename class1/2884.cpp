#include <iostream>
using namespace std;
int H, M;
int main() {
    scanf("%d %d", &H, &M);
    M-=45;
    if (M < 0) {M+=60; H-=1;}
    if (H < 0) {H+=24;}
    printf("%d %d",H, M);
}