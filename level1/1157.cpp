#include <iostream>
#include <string>
#include <map>
using namespace std;
string words;
map<char, int> letter_num;
size_t pos=0;

int main() {
    getline(cin, words);
    
    for(const auto& c : words) {
        char temp = c;
        if (temp >= 97) {temp -= 32;}
        
        auto iter = letter_num.find(temp);
        if(iter == letter_num.end()) {letter_num.insert({temp, 1});}
        else if(iter != letter_num.end()) {iter->second++;}
    }
 
    int max_count=0;
    bool max_letter = false;
    map<char, int>::iterator max_iter;
    for (map<char, int>::iterator iter = letter_num.begin(); iter != letter_num.end(); iter++) {
        if (iter->second > max_count) {
            max_count = iter->second;
            max_iter = iter;
            max_letter = true;
        }
        else if(iter->second == max_count) {max_letter=false;}
    }
    
    if(max_letter) {printf("%c\n", max_iter->first);}
    else{printf("?\n");}
}