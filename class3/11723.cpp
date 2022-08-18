#include <iostream>
#include <string>
#include <vector>
using namespace std;

// hash structure
bool S[21];
int M, x;
string method; 

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cin >> M;
    
    for (int i=0; i<M; i++) {
        cin >> method;
        
        if (method == "all") {
            for (int j=1; j<21; j++) { S[j] = true;}
            continue;
        }
        else if (method == "empty") {
            for (int j=1; j<21; j++) { S[j] = false;}
            continue;        
        }

        cin >> x;
        if (method == "add") {S[x] = true;}
        else if (method == "remove") {S[x] = false;}
        else if (method == "check") {cout << S[x] << "\n";}
        else if (method == "toggle") {S[x] = !S[x];}
    }
}