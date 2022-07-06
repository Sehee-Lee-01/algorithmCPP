#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> input;

int main() {
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++) {input.push_back(i);}
    printf("<");
    int index = K-1;
    vector<int>::iterator del_iter;
    while (!input.empty()) {
        if (index>=input.size()) {
            while(index>=input.size()){index-=input.size();}
            del_iter = input.begin()+index;
        }
        else {del_iter = input.begin()+index;}
        printf("%d",*del_iter);
        input.erase(del_iter);
        if(input.empty()) {break;} else {printf(", ");}
        index+=(K-1);
    }
    printf(">\n");
}