#include <iostream>
#include <string>
using namespace std;
int N, sum=0;
string input;
int main() {
    scanf("%d", &N);
    cin >> input; 
    for(int i=0; i<N; i++) {sum +=  (input[i] - '0');}
    printf("%d",sum);
}