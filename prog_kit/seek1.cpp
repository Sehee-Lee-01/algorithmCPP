#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> su1_ans = {1,2,3,4,5},
                su2_ans = {2,1,2,3,2,4,2,5},
                su3_ans = {3,3,1,1,2,2,4,4,5,5};
    int sc1=0, sc2=0, sc3=0, idx1=0, idx2=0, idx3=0;
    
    for (auto quiz_ans: answers) {
        if (quiz_ans==su1_ans[idx1++]) {sc1++;}
        if (quiz_ans==su2_ans[idx2++]) {sc2++;}
        if (quiz_ans==su3_ans[idx3++]) {sc3++;}
        
        if (idx1==su1_ans.size()) {idx1=0;}
        if (idx2==su2_ans.size()) {idx2=0;}
        if (idx3==su3_ans.size()) {idx3=0;}
    }
    
    if ((sc1==sc2)&&(sc2==sc3)) {answer.push_back(1); answer.push_back(2); answer.push_back(3);}
    if ((sc1==sc2)&&(sc1>sc3)) {answer.push_back(1); answer.push_back(2);}
    if ((sc2==sc3)&&(sc2>sc1)) {answer.push_back(2); answer.push_back(3);}
    if ((sc1==sc3)&&(sc3>sc2)) {answer.push_back(1); answer.push_back(3);}
    if ((sc1>sc2)&&(sc1>sc3)) {answer.push_back(1);}
    if ((sc2>sc1)&&(sc2>sc3)) {answer.push_back(2);}
    if ((sc3>sc1)&&(sc3>sc2)) {answer.push_back(3);}
    
    return answer;
}