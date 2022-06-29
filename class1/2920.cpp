#include <iostream>
using namespace std;
int temp, curr;
string state;
int main() {
    scanf("%d", &temp);
    for(int i=0; i<7; i++){
        scanf("%d", &curr);
        if((temp > curr)&&(state == "ascending")) {state = "mixed"; break;}
        else if (temp > curr) {state = "descending";}
        
        if((temp < curr)&&(state == "descending")) {state = "mixed"; break;}
        else if (temp < curr) {state = "ascending";}
        
        temp = curr;
    }

    cout << state << endl;
}