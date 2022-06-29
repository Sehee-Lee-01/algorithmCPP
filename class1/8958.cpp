#include <iostream>
#include <string>
using namespace std;
int testcase, acc=0, sum=0;
int main() {
    scanf("%d", &testcase);
    for(int i=0; i<testcase; i++) {
        string temp; cin >> temp;
        for (int j=0; j<temp.length(); j++) {
            if (temp[j]=='O') {acc++;sum+=acc;}
            else {acc=0;}
        }
        printf("%d\n", sum);
        acc=0; sum=0;
    }
}