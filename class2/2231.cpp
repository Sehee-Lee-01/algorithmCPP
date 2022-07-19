#include <iostream>
#include <string>
using namespace std;
string input;
int main() {
    cin >> input;
    int N = stoi(input);
    int N_len = input.length();
    for (int i=10*(N_len-1); i<N; i++) {
        int sum = i;
        string st_i = to_string(i);
        for (auto element : st_i) { sum+= (element -'0');}
        if (sum==N) {printf("%d\n", i); return 0;}
    }
    printf("0\n");
}