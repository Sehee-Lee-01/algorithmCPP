#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> cards;

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {cards.push(i);}
    while(cards.size()!=1) {
        // printf("top %d\n", cards.front());
        cards.pop();
        int front_card = cards.front();
        // printf("second %d\n", cards.front());
        cards.pop(); cards.push(front_card);
    }
    printf("%d\n", cards.front());
}