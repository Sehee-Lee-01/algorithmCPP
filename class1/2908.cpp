#include <iostream>
#include <string>
using namespace std;

string a,b, new_a, new_b;
int new_int_a, new_int_b;
int main() {
    cin >> a >> b;
    for (int i=2; i>=0; i--){
        new_a.push_back(a[i]); new_b.push_back(b[i]);
    }
    new_int_a = stoi(new_a); new_int_b = stoi(new_b);
    if(new_int_a > new_int_b) {printf("%d", new_int_a);}
    else {printf("%d", new_int_b);}
}