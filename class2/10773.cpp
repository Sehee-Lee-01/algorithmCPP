#include <iostream>
#include <vector>
using namespace std;
unsigned int K, temp, sum;
vector<int> jamin;
int main() {
    scanf("%d\n", &K);
    for (int i=0; i<K; i++) {
        scanf("%d\n", &temp);
        if (temp!=0) {
            jamin.push_back(temp);
        }
        else {jamin.pop_back();}
    }
    for (auto element : jamin) {
        sum+=element;
    }
    printf("%d\n", sum);
}