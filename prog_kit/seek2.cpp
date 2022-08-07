#include <string>
#include <vector>
using namespace std;

bool eratos[10000000];
int num_cnt[10];

int solution(string numbers) {
    //초기화
    int answer = 0;
    for (auto num: numbers) {num_cnt[num-'0']++;}
    for (int i=0; i<10000000; i++) {eratos[i] = true;}
    eratos[0]=false; eratos[1]=false; 
    
    // 에라토스테네스의 체 만들기
    for (int i=2; i<5000000; i++) {
        if (eratos[i]==false) {continue;}
        int mul_num = 2;
        while(i*mul_num<10000000) {eratos[i*mul_num] = false; mul_num++;}
    }
    
    //  제작 가능한 소수 찾기
    for (int i=2; i<10000000; i++) {
        // 소수일 경우
        if (eratos[i]) {
            string prime_num = to_string(i); 
            int num_cnt_cp[10], j=0;
            for (int k=0; k<10; k++) {num_cnt_cp[k]=num_cnt[k];}
            
            // 소수의 한 자리씩 조합이 가능한지 카운트에서 뺌
            for (; j<prime_num.length(); j++) {
                // 들어갈 수 있으면 카운트--
                if (num_cnt_cp[prime_num[j]-'0']>0) {num_cnt_cp[prime_num[j]-'0']--;}
                // 더이상 numbers에서 자리에 들어갈 '수'가 없으면 다음 소수 찾기
                else {break;}
            }
            //다 문제없이 소수의 각 자리를 순회했으면
            if (j==prime_num.length()) {answer++;}
        }
    }
    return answer;
}