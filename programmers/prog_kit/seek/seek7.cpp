// 중복 순열 경우의 수를 구해서 sort 해서 푸는 문제 같다.(dfs)
#include <algorithm>
#include <string>
#include <vector>
#define DEPTH 5
using namespace std;

// char 사전 순서 정의
const vector<char> charList = {'A','E','I','O','U'};

// 모든 경우의 수 list
vector<string> numberOfCases;

// fullDepth 수 만큼의 글자 수로 만들 수 있는 경우의 수
void cases (int selectArray[], int fullDepth, int depth=0) {
    // depth가 채워졌으면 push_back
    if (depth==fullDepth) {
        string temp="";
        for (int i=0; i<fullDepth; i++) {
            temp+=selectArray[i];
        }
        numberOfCases.push_back(temp);
        return;
    }
    // depth가 아직 안채워졌으면 재귀
    for (auto element: charList) {
        selectArray[depth]=element;
        cases(selectArray, fullDepth, depth+1);
    }
}

int solution(const string word) {
    
    // 경우의 수 numberOfCases에 push_back 하기
    for (int fullDepth=1; fullDepth<=DEPTH; fullDepth++) {
        int selectArray[fullDepth];
        cases(selectArray, fullDepth, 0);
    }

    // sort()
    sort(numberOfCases.begin(), numberOfCases.end());
    
    // find(word)
    auto indexIter = find(numberOfCases.begin(), numberOfCases.end(), word);
    
    // answer
    int answer = indexIter-numberOfCases.begin()+1;
    return answer;
}