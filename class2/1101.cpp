#include <iostream>
#include <algorithm>
#include <string>
#include<set>
#include<vector>
using namespace std;
int testcase;
string temp;
set<string> word_length[50];

int main() {
    scanf("%d", &testcase);
    for(int i=0; i<testcase; i++) {
        cin >> temp;
        word_length[temp.length()-1].insert(temp);    
    }
    
    for (int i=0; i<50; i++) {
        auto iter = word_length[i].begin(); 
        vector<string> temp_vec;
        for(;iter!= word_length[i].end();iter++) {
            temp_vec.push_back(*iter);
        }
        sort(temp_vec.begin(), temp_vec.end());
        for(auto &index : temp_vec) {
            cout << index << "\n";
        }
    }
}