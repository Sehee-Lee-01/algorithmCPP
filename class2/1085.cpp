#include <iostream>
#include <cmath>
using namespace std;
int x, y, w, h, go=1000;
int main() {
    scanf("%d %d %d %d",&x, &y, &w, &h);
    if ((x-0)<go) {go=x-0;}
    if ((w-x)<go) {go=w-x;}
    if ((y-0)<go) {go=y-0;}
    if ((h-y)<go) {go=h-y;}
    printf("%d", go);
}