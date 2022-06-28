#include <iostream>
using namespace std;
int a, b;
int main() {
    scanf("%d %d\n", &a, &b);
    if(a>b){cout<< ">" << endl;}
    else if(a<b){cout<< "<" << endl;}
    else {cout << "==" << endl;}
}