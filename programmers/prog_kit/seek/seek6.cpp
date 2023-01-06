#include <set>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    // 와이어 연결 구조 정리(1~n 노드까지)
    vector<int> relation[n+1];
    for (auto wire: wires) {
        relation[wire[0]].push_back(wire[1]);
        relation[wire[1]].push_back(wire[0]);
    }        
    
    // 답
    int answer = n;
    
    // [완전 탐색] 연결 하나씩 끊어보면서 수 찾기(deleteV1<deleteV2) 
    for (int deleteWire=0; deleteWire<wires.size(); deleteWire++) {
        // 연결을 참고 안하는 숫자들(삭제를 안하고 참고를 제외하는 형식으로 진행)
        int deleteV1 = wires[deleteWire][0], deleteV2 = wires[deleteWire][1];
        
        // 방문 노드 셋, 방문할 노드 스택
        set<int> visited; vector<int> visitStack;
        
        // v1이 1인 연결부터 탐색
        visitStack.push_back(1);
        
        // 방문 시작(두 개 중 한 개의 '연결망'만 탐색)
        while(!visitStack.empty()) {
            // stack에서 현재 루프에서 방문한 v1 빼기 
            int v1 = visitStack.back();
            visitStack.pop_back(); visited.insert(v1); 
            
            // v1 노드와 연결된 v2 노드들 stack에 넣기
            for (auto v2:relation[v1]) {
                // 삭제한 연결([deleteV1, deleteV2]) 참고 안함 
                if (((v1==deleteV1)&&(v2==deleteV2))||((v1==deleteV2)&&(v2==deleteV1))) {continue;}
                // v2가 방문하지 않은 노드이면 참고
                if ((visited.find(v2)==visited.end())) {visitStack.push_back(v2);}
            }
        }
            
        // 방문 노드 갯수 세기, 남은 연결망과 차이 구하기
        int webCount1 = visited.size(), webCount2 = n - webCount1;
        int diffCount = abs(webCount1-webCount2);
        
        if (diffCount<answer) {answer = diffCount;}
    }
    return answer;
}