#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, temp;
vector<int> withdrawalTime; 
int main() {
    cin >> N;
    
    // get
    for(int i=0; i<N; i++) {
        cin >> temp;
        withdrawalTime.push_back(temp);
    }
    
    // sort
    sort(withdrawalTime.begin(), withdrawalTime.end());
    
    // greedy
    int sum=0, perTime=0;
    for (int i=0; i<N; i++) {
        perTime+=withdrawalTime[i];
        sum += perTime;
    }    
    // print
    cout << sum << "\n";
}