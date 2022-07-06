#include <iostream>
using namespace std;

int N, M, sub_time, add_time;
unsigned int B, temp, curr_sum;
int main() {
    scanf("%d %d %d", &N, &M, &B);
    int ground[N][M];
    for (int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d", &temp);
            ground[i][j] = temp;
            curr_sum += temp;
        }
    }
    unsigned int sub_height = curr_sum/(N*M), add_height = curr_sum/(N*M)+1;
    int sub_B=B, add_B=B;
    for (int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int temp1 = ground[i][j]-sub_height;
            int temp2 = ground[i][j]-add_height;
            if (temp1<0) {sub_time-=temp1; sub_B--;}
            else {
                sub_time+=(2*temp1); 
                if (temp1!=0) {sub_B++;}
            }
            if (temp2<0) {add_time-=temp2; add_B--;}
            else {
                add_time+=(2*temp2); 
                if (temp2 !=0) {add_B++;}
            }
            printf("%d:%d %d:%d dada\n", temp1,sub_time, temp2,add_time);
        }
    }
    printf("%d:%d:%d %d:%d:%d nana\n", sub_height, sub_B,sub_time, add_height,add_B, add_time);
    if (sub_B<0) {printf("%d %d\n", add_time, add_height); return 0;}
    if (add_B<0) {printf("%d %d\n", sub_time, sub_height); return 0;}
    if(sub_time>=add_time) {printf("%d %d\n", add_time, add_height); return 0;}
    printf("%d %d\n", sub_time, sub_height); return 0;
}