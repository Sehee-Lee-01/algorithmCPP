#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    // 자르는 기준점 = sub_topping2의 시작
    auto start_cake2 = topping.begin()+1;
    while (start_cake2!=topping.end()) {
        int cake1[10001], cake2[10001], cnt_top1=0, cnt_top2=0; // 다 넣고 나중에 size로 토핑 갯수 세기
        for (int i=0; i<=10000; i++) {cake1[i]=0; cake2[i]=0;}
        for (auto iter1=topping.begin();iter1!=start_cake2;iter1++) {cake1[*iter1]++;}
        for (auto iter2=start_cake2;iter2!=topping.end();iter2++) {cake2[*iter2]++;}
        for (int i=0; i<=10000; i++) {
            if (cake1[i]>0) {cnt_top1++;} 
            if (cake2[i]>0) {cnt_top2++;}
        }
        if (cnt_top1 == cnt_top2) {answer++;}
        start_cake2++;
    }
    return answer;
}