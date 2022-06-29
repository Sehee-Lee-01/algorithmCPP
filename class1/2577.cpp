#include <iostream>
#include<string>
using namespace std;

int a,b,c, mul, num_array[10];
string int_st;
int main() {
    scanf("%d %d %d", &a,&b,&c);
    mul = a*b*c;
    int_st = to_string(mul);
    for(auto& c : int_st) {
        int temp = c-'0';
        num_array[temp]++;
    }
    for(int i=0; i<10; i++){printf("%d\n", num_array[i]);}
}