#include <iostream>
#include <string>
using namespace std;
string tmp;
int main() {
    while (1)
    {
        cin >> tmp;
        bool pel = true;

        if (tmp[0] == '0') break;
        int end_index = (tmp.length()/2-1);
        for(int i=0; i<=end_index; i++) {
            if (tmp[i] != tmp[tmp.length()-1-i]) {pel = false; break;}
        }

        if(pel) {printf("yes\n");} else {printf("no\n");}
    }
}