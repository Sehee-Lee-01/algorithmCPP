#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    // 현재 다리 위에 있는 트럭(시작, 끝)
    int curr_start = 0, curr_end = 0;
    // 현재 다리 위 트럭 무게, 길이(갯수)
    int curr_weight = truck_weights[curr_start], curr_length = 1;
    
    while(curr_start!=truck_weights.size()-1) {
        if(truck_weights[curr_start]+truck_weights[curr_start+1]<=weight) {
            
        }
    }
    
    return answer;
}