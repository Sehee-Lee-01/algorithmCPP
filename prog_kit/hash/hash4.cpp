#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, vector<string>> organize_clothes;
    for (auto element: clothes) {
        string cloth_name = element[0], cloth_type = element[1];
        auto find_type = organize_clothes.find(element[1]);
        if (find_type==organize_clothes.end()) {organize_clothes.insert({element[1], {element[0]}});}
        else {find_type->second.push_back(element[0]);}
    }
    int answer = 1;
    for (auto clothes: organize_clothes) {
        answer*=(clothes.second.size()+1);
    }
    return answer-1;
}