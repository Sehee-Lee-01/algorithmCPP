#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for (auto sources_iter=sources.begin();sources_iter!=sources.end(); sources_iter++) {
        // *sources_iter와 목적지가 같으면
        if (*sources_iter==destination) {answer.push_back(0);}
        
    }
    return answer;
}