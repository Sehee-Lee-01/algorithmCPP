#include <iostream>
using namespace std;
unsigned int A,B,V, climb, day, day_mod, day_sum;

int main() {
    scanf("%d %d %d", &A, &B, &V);
    day_mod = V%(A-B);

    day = V/(A-B); day_sum = (day)*(A-B)+B;
    
    if (day_mod!=0) {day++;day_sum+=(A-B);}

    while(day_sum>=V) {
        day--;
        day_sum+=(B - A);
    }
    if (day_sum<V) {day++;}

    printf("%d\n", day);
}