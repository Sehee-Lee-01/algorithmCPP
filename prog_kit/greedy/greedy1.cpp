#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> new_reserve;
    for (auto &reserve_num: reserve){new_reserve.push_back(reserve_num);}
    for (auto &reserve_num: new_reserve) {
        auto lost_iter = find(lost.begin(), lost.end(), reserve_num);
        auto reserve_iter = find(reserve.begin(), reserve.end(), reserve_num);
        if (lost_iter != lost.end()) {
            lost.erase(lost_iter); reserve.erase(reserve_iter);
        }
    }
    
    sort(reserve.begin(), reserve.end());
    for (auto &reserve_num: reserve) {        
        auto iter_minus = find(lost.begin(), lost.end(), reserve_num-1);
        if(iter_minus!=lost.end()) {lost.erase(iter_minus); continue;}
        auto iter_plus = find(lost.begin(), lost.end(), reserve_num+1);
        if(iter_plus!=lost.end()) {lost.erase(iter_plus); continue;}
    }
    
    answer-=lost.size();    
    return answer;
}