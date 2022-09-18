#include <vector>
#include <algorithm>
using namespace std;

// 소모 피로도를 오름차순으로 정리하되 필요 피로도는 내림차순으로 정리(x)
// (필요 피로도-소모 피로도) 내림차순으로 정리하되 값이 같다면 필요 피로도 오름차순으로 정리
bool cmp (vector<int> a, vector<int> b) {
    int diff_a = a[0]-a[1], diff_b = b[0] - b[1];
    if (diff_a == diff_b) {
        return a[0] < b[0];
    }
    return diff_a > diff_b;
    
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    // 특정 기준으로 정렬
    sort(dungeons.begin(), dungeons.end(), cmp);
    
    // 정렬된 던전을 순서대로 돌면서 피로도 유효할 때까지 빼주기
    for (auto element: dungeons) {
        if (k>=element[0]) {
            k-=element[1];
            answer++;
        }
    }
    
    return answer;
}