#include <iostream>
#include <string>
using namespace std;
int T, is_open;
string temp;
int main() {
    scanf("%d\n",&T);
    for (int i=0; i<T; i++) {
        is_open=0;
        getline(cin, temp);
        
        for (auto &element: temp) {
            if (element == '(') {is_open++;}
            if (element == ')') {
                is_open--;
            if (is_open<0) {break;}
            }
            // printf("%d\n", is_open);
        }
        if (is_open == 0) {printf("YES\n");} else {printf("NO\n");}
    }
}