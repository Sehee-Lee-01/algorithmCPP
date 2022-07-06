#include <iostream>
using namespace std;
#define max_time 500000*256

int N, M, B, temp, min_time=max_time, min_time_height=0, curr_B, curr_time;
int main() {
    scanf("%d %d %d", &N, &M, &B);
    int ground[N][M];
    for (int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d", &temp);
            ground[i][j] = temp;
        }
    }

    for(int height=0; height<=256; height++) {
        curr_time=0; curr_B=B;
        for (int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                temp = ground[i][j]-height;
                if (temp<0) {
                    curr_time-=temp; 
                    curr_B+=temp;
                }
                else {
                    curr_time+=(2*temp); 
                    curr_B+=temp;
                }
            }
        }
        if (curr_B>=0) {
            if (curr_time<min_time) {min_time=curr_time;min_time_height = height;}
            if ((curr_time==min_time)&&(height>min_time_height)) {min_time_height = height;}
        }
    }
    printf("%d %d\n", min_time, min_time_height); return 0;
}