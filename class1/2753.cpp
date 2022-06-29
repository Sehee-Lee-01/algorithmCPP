#include <iostream>
using namespace std;
int Y;
int main() {
    scanf("%d", &Y);
    if((Y%4 == 0)&&((Y%100!=0))) {printf("1");}
    else if(Y%400==0) {printf("1");}
    else {printf("0");}
}