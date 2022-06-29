#include <iostream>
#include <string>
using namespace std;
string input;
int a,b;
int main() {
    while (1) {
        getline(cin, input);
        if(input == "") break;
        a = input[0] - '0'; b = input[2] - '0';
        printf("%d\n", a+b);
    }
}