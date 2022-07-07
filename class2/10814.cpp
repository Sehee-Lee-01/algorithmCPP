#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

int N, age;
string name;
map<int, list<string>> input;

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> age >> name;
        auto iter = input.find(age);
        if (iter != input.end()) {iter->second.push_back(name);}
        else {
            list<string> new_str; new_str.push_back(name);
            input.insert({age,new_str});
        }  
    }
    for (auto &i : input) {
        for(auto &j : i.second) {
            printf("%d %s\n", i.first, j.c_str());
        }
    }    
}