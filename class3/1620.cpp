#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    string temp, dictionary[N]; 
    
    //Push
    for (int i=0; i<N; i++) {
        cin >> temp;
        dictionary[i] = temp;
    }
    
    // Quiz
    for (int i=0; i<M; i++) {
        cin >> temp;
        // is int
        if (temp[0]<65) {cout << dictionary[stoi(temp)-1] << "\n";}
        // is str
        else {
            for (int j=0; j<N; j++) {
                if (dictionary[j]==temp) {cout << j+1 << "\n"; break;}
            }
        }
    }
}