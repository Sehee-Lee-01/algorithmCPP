// 큐 문제 추정
#include <vector>
using namespace std;

// 포장 갯수
int hamburger = 0;

int solution(vector<int> ingredient) {
    // 재료가 부족한 경우
    if (ingredient.size()<4) {return hamburger;}

    auto iter=ingredient.begin();
    while ((iter-ingredient.begin()+3)<ingredient.size()) {
        // 여기서 탐색된 1은 무조건 시작으로 본다.
        // 순서: 1(빵)-2(야채)-3(고기)-1(빵)
        if ((*iter==1)&&(*(iter+1)==2)&&(*(iter+2)==3)&&(*(iter+3)==1)) {
            // 순서가 맞다면 
            // 포장 갯수 1 늘리고
            hamburger++;
            // 삭제하고 삭제 직후 값에 맞춰서 이터레이터 조정
            iter = ingredient.erase(iter, iter+4);

            // 삭제한 직후의 값 == end (종료)
            if (iter==ingredient.end()) {break;}

            // 삭제한 직후의 값 == 1 (삭제 직후-3부터 탐색시작)
            if (*iter==1) {
                if ((iter-ingredient.begin()-3)>=0) {iter-=3;}
                else {iter++; continue;}
            } 
            if (*iter==2) {iter-=1;} // 삭제한 직후의 값 == 2 (삭제 직후-1부터 탐색시작)
            if (*iter==3) {iter-=2;} // 삭제한 직후의 값 == 3 (삭제 직후-2부터 탐색 시작)
            // 지정한 iter로 재시작
            continue;
        }
        // 순서가 맞지 않다면 계속 진행
        iter++;
    }
    return hamburger;
}