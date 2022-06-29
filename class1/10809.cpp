#include <iostream>
#include <string>
using namespace std;
int alpha[26];
string input;
int main() {
    for(int i=0; i<26; i++){alpha[i] = -1;}
    cin >> input;
    for(int i=0; i<input.length();i++){
        int temp = input[i] - 'a';
        if(alpha[temp]==-1) alpha[temp]=i;
    }
    for(int i=0; i<26; i++) printf("%d ", alpha[i]);
}