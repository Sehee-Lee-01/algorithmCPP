#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, M;
    string temp;
    set<string> haventListenList; 
    vector<string> haventListenSeenList;
    cin >> N >> M;
    
    // get haven't listened people
    for (int i=0;i<N;i++) {
        cin >> temp;
        haventListenList.insert(temp);
    } 
    // get haven't seen people & find them in haven't listened people list
    for (int i=0;i<M;i++) {
        cin >> temp;
        auto haventSeenPerson = haventListenList.find(temp);
        if (haventSeenPerson!=haventListenList.end()) {haventListenSeenList.push_back(temp);} 
    }

    // sort
    sort(haventListenSeenList.begin(), haventListenSeenList.end());

    // print result
    cout << haventListenSeenList.size() << "\n";
    for (auto haventListenSeenPerson: haventListenSeenList) {
        cout << haventListenSeenPerson << "\n";
    }
}