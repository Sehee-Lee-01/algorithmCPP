#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int testcase, temp, curr=1;
vector<char> result;
stack<int> sequence; 
int main() {
    sequence.push(0);
    scanf("%d", &testcase);
    for (int i=0; i<testcase; i++) {
        scanf("%d", &temp);
        if (temp >= curr) {
            while (curr <= temp) {sequence.push(curr++); result.push_back('+');}
            sequence.pop(); result.push_back('-');
        }
        else {
            if(sequence.top()!=temp) {result.push_back('+'); break;}
            else {sequence.pop(); result.push_back('-');}
        }
    }
    if (result.back() != '-') {printf("NO\n");}
    else {for(auto &s : result) {printf("%c\n", s);}}
}