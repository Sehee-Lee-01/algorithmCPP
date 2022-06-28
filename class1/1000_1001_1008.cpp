#include <iostream>
using namespace std;

double a, b;

int main() {
    scanf("%lf %lf", &a, &b);    
    //int sum = a + b;
    //int ded = a -b;

    double div = a/b;
    printf("%.10lf", div);
}