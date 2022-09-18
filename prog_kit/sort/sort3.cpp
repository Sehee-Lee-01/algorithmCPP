#include <vector>
#include <algorithm>

using namespace std;
// 전역변수 설정
int h=1;
// find 조건
bool over_h (int a) {return a>=h;}
int solution(vector<int> citations) {
    int answer = 0;
    // 인용수 정렬
    sort(citations.begin(), citations.end());
    // 현재 값
    // 1~1000 하나씩 확인(h 최댓값 찾기)
    while(h<=1000) {
        auto find_over_h = find_if(citations.begin(), citations.end(), over_h);
        int count_under_h = find_over_h-citations.begin();
        int count_over_h = citations.size()-count_under_h;
        // 조건이 맞다면(인용수 h 이상인 논문이 h편이상이고 나머지가 h편 이하라면) 최대값 업데이트
        if ((count_over_h>=h)&&(count_under_h<=h)) {
            if (h>answer) {answer=h;}
        }
        h++;
    }
    return answer;
}