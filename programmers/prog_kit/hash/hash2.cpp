#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> people_list;
    // make hash map
    for (auto name: participant) {
        auto find_iter = people_list.find(name);
        if(find_iter==people_list.end()) {
            people_list.insert({name, 1});
        }
        else {find_iter->second++;}
    }
    // sub  completion people
    for (auto name: completion) {
        auto find_iter = people_list.find(name);
        find_iter->second--;
    }
    // check 
    for (auto name_count: people_list) {
        if (name_count.second>0) {return name_count.first;}
    }
}