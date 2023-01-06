#include <string>
#include <vector>
#include <map>
using namespace std;

struct k_num {
    int x_num;
    int y_num;
    k_num (int a, int b) : x_num(a), y_num(b) {}
};
map<int, k_num> k_total;

string solution(string X, string Y) {
    string answer = "";
    for (auto x_element: X) {
        auto find_iter = k_total.find(x_element-'0');
        if (find_iter==k_total.end()) {
            k_num temp = k_num(1,0);
            k_total.insert({x_element-'0', temp});
        }
        else {find_iter->second.x_num++;}
    }
    for (auto y_element: Y) {
        auto find_iter = k_total.find(y_element-'0');
        if (find_iter==k_total.end()) {
            k_num temp = k_num(0,1);
            k_total.insert({y_element-'0', temp});
        }
        else {find_iter->second.y_num++;}
    }
    auto r_iter = k_total.rbegin();
    while (r_iter != k_total.rend()) {
        if ((r_iter->second.x_num!=0)&&(r_iter->second.y_num!=0)) {
            if (r_iter->second.x_num > r_iter->second.y_num) {
                for (int i=0; i<r_iter->second.y_num; i++) {
                    answer+=to_string(r_iter->first);
                }
            }
            else {
                for (int i=0; i<r_iter->second.x_num; i++) {
                    answer+=to_string(r_iter->first);
                }
            }
        }
        r_iter++;
    }
    if(answer[0]=='0') {answer="0";}
    if (answer=="") {answer += "-1";}
    return answer;
}