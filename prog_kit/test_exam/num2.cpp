#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for (int i=0; i<=discount.size()-10; i++) {
        vector<int> number_cp = number;
        for (int j=i; j<i+10; j++) {
            auto find_iter = find(want.begin(), want.end(), discount[j]);
            if (find_iter!=want.end()) {
                number_cp[find_iter-want.begin()]--;
            }
        }
        int sum=0;
        for (int j=0; j<want.size(); j++) {sum += number_cp[j];}
        if (sum<=0) {answer++;}
    }
    return answer;
}