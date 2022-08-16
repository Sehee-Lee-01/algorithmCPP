#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    // 순열 사용을 위한 인덱스 리스트 만들기
    vector<int> index_list;
    for (int i=0; i<dungeons.size(); i++) {index_list.push_back(i);}
    
    // 던전을 (순열)정렬된 인덱스 순서대로 돈다
     while (next_permutation(index_list.begin(), index_list.end())) {
        int temp_k=k;
        int temp_answer=0;
        for (auto element: index_list) {
            if (temp_k>=dungeons[element][0]) {
                temp_k-=dungeons[element][1];
                temp_answer++;
            } else {break;}
        } 
        if (temp_answer>answer) {answer=temp_answer;}
    }
    
    return answer;
}