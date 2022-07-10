#include <iostream>
#include <vector>
using namespace std;
int N, M, temp, sum, max_sum;
vector<int> input;
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        scanf("%d", &temp);
        input.push_back(temp);
    }
    for(int i=0; i<input.size()-2; i++) {
        for(int j=i+1; j<input.size()-1; j++) {
            for(int k=j+1; k<input.size(); k++) {
                sum = input[i]+input[j]+input[k];
                if((sum > max_sum)&&(sum<=M)) {
                    
                    // printf("%d %d %d\n", input[i],input[j],input[k]);
                    max_sum=sum;
                }
            }
        }
    }
    printf("%d\n", max_sum);
}