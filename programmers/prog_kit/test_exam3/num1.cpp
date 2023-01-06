// 그리디 문제로 추정
#include <vector>
using namespace std;

int total_income = 0;

int solution(int outlay, int income, int holding) {
    if (holding<outlay) {return total_income;}    
    // 현재 가진 병으로 낼 수 있을 만큼 병을 내기
    while (holding>=outlay) {
        holding-=outlay;
        holding+=income;
        total_income+=income;
    }
    return total_income;
}