#include <iostream>
using namespace std;
int dan;
int main() {
    scanf("%d", &dan);
    for (int i=1; i<10; i++) {printf("%d * %d = %d\n", dan, i, dan*i);}
}