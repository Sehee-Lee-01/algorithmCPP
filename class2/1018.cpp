#include <iostream>
using namespace std;
# define MAX 2500
int M,N, resultb=MAX, resultw=MAX;
char temp;
int main() {
    scanf("%d %d", &M, &N);
    char chess[M][N];
    for(int i=0; i<M; i++) for(int j=0; j<N; j++) cin >> chess[i][j];

    for (int a=0; a<M-7; a++) {
        for (int b=0; b<N-7; b++) {
            int tmpb=0, tmpw=0;
            for(int i=a; i<a+8; i++) {
                for(int j=b; j<b+8; j++) {
                    if (((i%2)==(j%2))) {temp='B';} else {temp = 'W';}
                    if (chess[i][j]!=temp) {tmpb++;} else {tmpw++;}
                }       
            }
            if (tmpb<resultb) {resultb=tmpb;} 
            if (tmpw<resultw) {resultw=tmpw;}
        }
    }
    
    if(resultb > resultw) {printf("%d", resultw);}
    else {printf("%d", resultb);}
}