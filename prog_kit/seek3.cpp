#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // (관계식) yellow = (width-2)*(height-2), brown = 2*(width-2)+2*(height-2)+4
    // (식 정리) width*height = brown+yellow (width>=height>=3, a와 b는 자연수)
    int by_mul = brown + yellow;
    // width와 height는 3부터 시작하므로 3부터 a*b까지 곱셈 경우의 수 탐색
    for (int height = 3; height<by_mul; height++) {
        // 나누어 떨어지고(weight = by_mul/height)
        // 해당 식 만족 (brown+4) = 2*(width+height)
        if ((by_mul%height==0)&&((brown+4)==2*(by_mul/height+height))) {
            answer.push_back(by_mul/height); // width
            answer.push_back(height); 
            break;
        }
    }
    return answer;
}
/*
처음에는 식을 완전히 정리해서 
    width*height = yellow + brown (3<=height<=width, 모든 변수는 자연수)
라고만 적용을 했다. 
이렇게 해서 테스트케이스3 (brown=21, yellow=24)의 답이 [16,3]이 나왔다. 
'정리된 식'으로만 보면 답은 맞지만 답으로 역으로 yellow, brown 값을 계산해보면 테스트케이스와 다른 값이 나온다.
'연립'된 식이기 때문에 연립되기 전의 식이 만족하는지는 반영을 안해서 이 테스트 케이스가 답이 제대로 안나왔다.
*/