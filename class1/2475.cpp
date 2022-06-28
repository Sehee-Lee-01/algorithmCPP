#include <iostream>
using namespace std;

int temp, sum=0, result;

int main() {
    for (int i=0; i<5; i++) {
        scanf("%d", &temp);
        sum += temp*temp;
    }
    printf("%d", sum%10);
}