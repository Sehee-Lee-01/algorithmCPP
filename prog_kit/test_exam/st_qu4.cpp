#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer, r_answer;
    auto iter_curr = prices.rbegin();
    for (int i=0; i< prices.size(); i++) {
        int count = 0;
        auto iter_check = prices.begin()+prices.size()-i-1;
        while (iter_check!=prices.begin()+prices.size()-1) {
            if (*iter_curr>*iter_check) {break;}
                count++;
                iter_check++;
        }
        r_answer.push_back(count);
        iter_curr++;
    }
    for (auto iter=r_answer.rbegin(); iter!=r_answer.rend(); iter++) {
        answer.push_back(*iter);
    }
    
    return answer;
}