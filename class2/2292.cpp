#include <iostream>
using namespace std;
unsigned int N, stage=2, stage_start=2, stage_end =stage_start+5, temp;
int main() {
    scanf("%d", &N);
    if (N==1) {printf("1\n"); return 0;}
    while (true) {
        // printf("stage: %d start: %d end: %d\n", stage, stage_start, stage_end);
        if ((stage_start<=N)&&(N<=stage_end)) {printf("%d\n", stage); return 0;}
        stage_start=stage_end+1;
        stage_end= stage_start + stage*6-1;
        stage++;
    }   
}