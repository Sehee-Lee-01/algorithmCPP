#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    queue<int> truck_queue;
    queue<pair<int,int>> curr_trucks; // 도로 현황, <차의 무게, 현재 위치(1~bridge_length)>
    
    // 큐로 바꾸기
    for (auto truck : truck_weights) {truck_queue.push(truck);}
    
    // 맨 앞차 기준으로 실행할 거라 첫 번째 차 들어온 것으로 초기화
    long long curr_weight=truck_queue.front(), curr_length=1; // 10000*10000 이라서 널널하게 롱롱
    curr_trucks.push({truck_queue.front(),1});
    truck_queue.pop();
        
    // 시작(맨 앞 차 기준)
    while(1) {
        // 맨앞 트럭이 빠져나가기 직전까지
        while(curr_trucks.front().second<bridge_length) {
            // 추가 하던 말던 우선 한 칸씩 이동
            for (int i=0; i<curr_length; i++) {
                int temp = curr_trucks.front().second+1;
                curr_trucks.push({curr_trucks.front().first, temp});
                curr_trucks.pop();
            }
            answer++;
            // 한 칸 이동하면서 추가 할 수 있으면 추가
            if ((!truck_queue.empty())&&(curr_weight+truck_queue.front()<=weight)&&(curr_length<bridge_length)) {
                //무게, 길이 업데이트
                curr_weight+=truck_queue.front();
                curr_length++;
                curr_trucks.push({truck_queue.front(),1});
                truck_queue.pop();
            }
        }
        // 그 후 맨 앞 트럭 삭제
        curr_weight-=curr_trucks.front().first;
        curr_length--;
        curr_trucks.pop();
        answer++; // 차 한 대 나감
        
        // 도로에 남은 차도 없고 대기 차도 없을 때 종료
        if ((curr_trucks.empty())&&(truck_queue.empty())) {break;}
        
        // 도로에 남은 차가 있을 때 다 이동시키기
        if (!curr_trucks.empty()) {
            for (int i=0; i<curr_length; i++) {
                int temp = curr_trucks.front().second+1;
                curr_trucks.push({curr_trucks.front().first, temp});
                curr_trucks.pop();                
            }
        }
        // 삭제 후 바로 차가 들어올 수 있다면 추가
        if ((!truck_queue.empty())&&(curr_weight+truck_queue.front()<=weight)&&(curr_length<bridge_length)) {
            curr_weight+= truck_queue.front();
            curr_length++;
            curr_trucks.push({truck_queue.front(),1});
            truck_queue.pop();
        }
    }
    return answer;
}