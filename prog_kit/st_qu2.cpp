#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    map<int, int> priorty_num; 

    // Save current priority and sort by hash (1~9)
    for (auto element: priorities) {
        auto iter = priorty_num.find(element);
        if (iter==priorty_num.end()) {priorty_num.insert({element, 1});}
        else {iter->second++;}
    }
    
    // Using iterator, check answer
    auto num_iter = priorty_num.rbegin(); // check priority which looking for.
    
    auto print_iter =find(priorities.begin(), priorities.end(),num_iter->first);
    int print_ind = print_iter - priorities.begin();
    answer++; num_iter->second--;
    
    while (print_ind != location) {
        if (num_iter->second==0){num_iter++;}
        
        auto curr_iter = find(print_iter+1, priorities.end(),num_iter->first);
        if (curr_iter == priorities.end()) {curr_iter = find(priorities.begin(), print_iter-1, num_iter->first);}
        
        print_iter = curr_iter; 
        print_ind = print_iter - priorities.begin();
        answer++; num_iter->second--;
    }
    
    return answer;
}