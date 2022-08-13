#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = {arr.begin(), arr.end()};
    if (arr.size()==1) {return {-1};}
    auto iter_min = answer.begin();
    for (auto it=answer.begin()+1; it!=answer.end(); it++){
        if(*iter_min>*it) {iter_min = it;}
    }
    answer.erase(iter_min);
    return answer;
}