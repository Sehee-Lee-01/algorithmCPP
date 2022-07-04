#include <iostream>
#include<vector>
#include<set>
using namespace std;

int testcase, N, M, temp, print_q;

int main() {
    scanf("%d", &testcase);
    for(int i=0; i<testcase; i++) {
        print_q=0;
        scanf("%d %d", &N, &M);
        vector<pair<int,int>> doc_queue;
        int priority_num[10]; for (int j=0; j<10; j++) {priority_num[j]=0;}

        for(int j=0; j<N; j++) {
            scanf("%d", &temp);
            priority_num[temp]++;
            doc_queue.push_back({temp,j});
        }

        for (int j=9; j>0; j--) {
            if (priority_num[j]!=0) {
                while(priority_num[j]>0) {
                        if((doc_queue.front().first == j)&&(doc_queue.front().second == M)) {printf("%d\n", ++print_q); break;}
                        if(doc_queue.front().first == j) {print_q++;priority_num[j]--;}
                        else {doc_queue.push_back(doc_queue.front());}
                        doc_queue.erase(doc_queue.begin());
                    // for(auto it=doc_queue.begin(); it!=doc_queue.end(); it++) {
                    //     printf("(%d, %d) ", it->first, it->second);
                    // } printf("\n");
                }
            }
        }
    }
}