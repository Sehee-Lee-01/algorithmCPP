#include <algorithm>
#include <map>
#include <set>
using namespace std;


int solution(vector<int> topping) {
    // 롤케이크에 있는 토핑(종류, 갯수) 탐색
    map<int,int> topping_type;
    for (auto type: topping) {
        auto find_type = topping_type.find(type);
        if (find_type==topping_type.end()) {topping_type.insert({type,1});}
        else {find_type->second++;}
    }
    
    // 한 칸씩 옮기면서 지우고 남겨진 토핑종류 확인
    int answer = 0;
    map<int,int> after_type= {topping_type.begin(), topping_type.end()};
    set<int> before_type;
    for (auto type: topping) {
        before_type.insert(type);
        auto find_type = after_type.find(type);
        find_type->second--;
        if (find_type->second == 0) {after_type.erase(type);} 

        // 자르고 남겨진 토핑 종류 카운트
        int cnt_after = after_type.size(), cnt_before = before_type.size();

        // 비슷하면 answer++
        if (cnt_before == cnt_after) {answer++;}
    }
    return answer;
}