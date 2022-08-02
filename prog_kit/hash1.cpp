#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int half_N = nums.size()/2;
    map<int, int> count_mon;
    for (auto pocketmon : nums) {
        auto find_mon = count_mon.find(pocketmon);
        if (find_mon==count_mon.end()) {
            count_mon.insert({pocketmon, 1});
        }
        else {find_mon->second++;}
    }
    if (half_N<=count_mon.size()) {return half_N;}
    return count_mon.size();
}