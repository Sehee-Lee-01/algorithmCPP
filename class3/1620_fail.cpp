#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    
    string temp, poketmonIndex[N];
    map <string, int> dictionary;
    
    //Push
    for (int i=0; i<N; i++) {
        cin >> temp;
        poketmonIndex[i] = temp;
        dictionary.insert({temp, i+1});
    }
    
    // Quiz
    for (int i=0; i<M; i++) {
        cin >> temp;
        // is string
        if (temp[0]>=65) {cout << dictionary.find(temp)->second << "\n";}
        // is int
        else {cout << poketmonIndex[stoi(temp)-1] << "\n";}
    }
}