#include <iostream>
using namespace std;
int testcase, a, b;
int main() {
    scanf("%d", &testcase);
    for (int i=0; i<testcase; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
}