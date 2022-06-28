#include <iostream>
using namespace std;

int input;
int main() {
    scanf("%d", &input);
    for (int i=0; i<input; i++) {
        for(int j=0; j<(input-i-1); j++) {
            printf(" ");
        }        
        for(int j=0; j<i+1; j++) {
            printf("*");
        }
        printf("\n");
    }
}