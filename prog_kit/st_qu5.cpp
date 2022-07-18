#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr.front());
    auto curr_iter = arr.begin()+1;
    while(curr_iter!=arr.end()) {
        if (answer.back() != *curr_iter) {
            answer.push_back(*curr_iter);
        }
        curr_iter++;
    }

    return answer;
}