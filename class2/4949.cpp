#include <iostream>
#include <string>
#include <stack>
using namespace std;
string input;
bool result;
int main() {
    while (1) {
        stack<char> gual_open; result=true;
        getline(cin, input); if((input == "")||(input==".")) break;
        
        for (auto &c : input) {
            if ((c == '(')||(c == '[')) {gual_open.push(c); continue;}
            
            if (c == ')') {
                if ((!gual_open.empty())&&(gual_open.top() == '(')) {gual_open.pop(); continue;}
                else {result=false; break;}
            }
            if (c == ']') {
                if ((!gual_open.empty())&&(gual_open.top() == '[')) {gual_open.pop(); continue;}
                else {result=false; break;}            
            }
            if (c == '.') {
                if (gual_open.empty()) {break;} else {result=false; break;}
            }
        }

        if(result) {printf("yes\n");} else {printf("no\n");}
    }
}