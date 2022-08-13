#include <string>
#include <vector>

using namespace std;
#define MAX 1000001
//init
bool erastos[MAX];

int solution(int n) {
    // 에라토스테네스의 체 만들기 
    for (int i=2; i<=n; i++) {
        erastos[i]=true;
    }
    erastos[0]=false; erastos[1]=false;
    
    for (int i=2; i<=n; i++) {
        int j=2;
        while (i*j<MAX) {
            erastos[i*j] = false;
            j++;
        }
    }
    
    // 소수 개수 찾기
    int answer = 0;
    for (int i=2; i<=n; i++) {
        if (erastos[i]==true) {answer++;}
    }
    
    return answer;
}