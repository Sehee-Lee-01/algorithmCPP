#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    map <string, int> dictionary;
    vector<string> poketmonIndex;
    int N, M;
    string temp;
    cin >> N >> M;
    vector<string> result;

    // Push
    for (int i=1; i<=N; i++) {
        cin >> temp;
        poketmonIndex.push_back(temp);
        dictionary.insert({temp, i});
    }

    // Quiz
    for (int i=0; i<M; i++) {
        cin >> temp;
        // is string
        if (temp[0]>=65) {result.push_back(to_string(dictionary[temp]));}
        // is int
        else {result.push_back(poketmonIndex[stoi(temp)-1]);}
    }
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << "\n";
    }
}