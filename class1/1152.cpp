#include <iostream>
#include <string>
using namespace std;

string words, str = " ";
size_t pos = 0;
int count = 0;

int main(void) {
    getline(cin, words);
    while (pos != string::npos) {   
        if(words.size()==1 && words.substr(0,1)==" ") {break;}
        else if ((pos == 0) && (words.substr(pos,1)==" ")) {
            if((pos + 1 == 1) && (words.substr(pos+1,1)!=" ")) {count=1;}
        }
        else if ((pos == 0) && (words.substr(pos,1)!=" ")) {count = 1;}
        else if ((pos == words.size()-1) && (words.substr(pos,1)==" ")) {}
        else if (words.substr(pos,1)==" ") {count++;}
    
        if (pos == words.size()) {break;}
        else {pos++;}
    }
    cout <<  count << endl;
}