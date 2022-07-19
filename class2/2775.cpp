#include <iostream>
#include <vector>
using namespace std;
int T, k, n;
int main() {
    scanf("%d", &T); 
    for (int i=0; i<T; i++) {
        scanf("%d %d", &k, &n);
        if (n==1) {printf("1\n"); continue;}
        
        vector<int> down;
        int sum=0;

        for (int j=0; j<n; j++) {down.push_back(j+1);} // 0 stair
        
        if (k!=1) {
            vector<int> up;
            for (int j=0; j<k-1; j++) { 
                for (int l=0; l<n; l++) {
                    sum+=down[l];
                    up.push_back(sum);
                }
                sum=0; down = up; up.clear();
            } // up = n-1 stair, down = n-2 stair
            
            sum=0;
            for(int j=0; j<n; j++) {sum+=up[j];}
        } 
        else { for (int j=0; j<n; j++) {sum+=down[j];} }
        
        printf("%d\n", sum);
    }
}