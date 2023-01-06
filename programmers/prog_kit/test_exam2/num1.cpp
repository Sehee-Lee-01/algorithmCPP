#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    // -a, -b, ... , (0), d, e, f 순으로 정렬
    sort(number.begin(), number.end());
    if (*number.begin()>0) {return 0;}
    // 가장 큰 양수부터 시작
    auto first_iter = number.rbegin();
    // 가장 큰 정수 1개(양수이거나 0이어야 함)를 기준으로
    // 가장 큰 수보다 작은 조건에 맞는 수 2개 찾기
    while (first_iter!=number.rbegin()+number.size()-2) {
        auto second_iter = first_iter+1; // 두 번째로 큰 수 
        while (second_iter!=number.rbegin()+number.size()-1) {
            auto third_iter = second_iter+1; // 세 번째로 큰 수(가장 작은 수)
            while (third_iter!=number.rend()) {
                int sum = *first_iter+*second_iter+*third_iter;
                if (sum==0) {answer++;}
                *third_iter++;
            }
            *second_iter++;
        }
        *first_iter++; 
    }
    return answer;
}