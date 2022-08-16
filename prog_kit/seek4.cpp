#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int ans_area=0, ans_w=0, ans_h=0; // ans_w >= ans_h
    for (auto element: sizes) {
        if (element[0]>element[1]) {
            if (element[0]>ans_w) {ans_w = element[0];}
            if (element[1]>ans_h) {ans_h = element[1];}
        }
        else {
            if (element[0]>ans_h) {ans_h = element[0];}
            if (element[1]>ans_w) {ans_w = element[1];}
        }
    }
    return ans_w*ans_h;
}