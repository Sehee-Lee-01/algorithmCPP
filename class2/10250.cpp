#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (a>b) {return b? GCD(b,a%b) : a;}
    else {return a? GCD(a,b%a): b;}
}
int LCM(int a, int b, int gcd) {return a*(b/gcd);}

int a,b, gcd;
int main() {
    scanf("%d %d", &a, &b);
    gcd = GCD(a,b);
    printf("%d\n%d\n", gcd, LCM(a, b, gcd));
}