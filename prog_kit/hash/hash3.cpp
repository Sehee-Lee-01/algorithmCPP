#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i=0; i<phone_book.size()-1; i++) {
        string tmp = phone_book[i], tmp_cmp = phone_book[i+1];
        string sub_tmp_cmp = tmp_cmp.substr(0,tmp.size());
        if (tmp == sub_tmp_cmp) {return false;}
    }
    return answer;
}