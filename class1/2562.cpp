#include <iostream>
using namespace std;
int temp, max_num, max_loc;
int main() {
    for(int i=0; i<9; i++) {
        scanf("%d", &temp);
        if (temp > max_num) {
            max_num = temp;
            max_loc = i+1;
        }
    }
    printf("%d\n%d\n", max_num, max_loc);
}