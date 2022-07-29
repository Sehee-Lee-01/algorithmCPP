#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    // set = {i,j,k}
    for (auto set: commands) {
        auto i = array.begin() + set[0] - 1; // array[i]
        auto after_j = array.begin() + set[1]; // array[j+1]
        
        // copy array from i to j
        vector<int> sub_vector;
        for (;i!=after_j; i++) {sub_vector.push_back(*i);}
        sort(sub_vector.begin(), sub_vector.end());
        
        auto k = sub_vector.begin() + set[2] - 1;
        answer.push_back(*k);
    }
    return answer;
}