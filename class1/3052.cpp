#include <iostream>
#include <map>
using namespace std;
int temp;
map<int, int> mod;
int main() {
    for(int i=0; i<10; i++){
        cin >> temp;
        temp%=42;
        auto iter =mod.find(temp);
        // is exist
        if (iter != mod.end()) {iter->second++;}
        // if new
        else {mod.insert({temp, 1});}
    }

    cout << mod.size() <<endl;
}