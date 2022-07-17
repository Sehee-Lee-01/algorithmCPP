#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer;
struct greaters {
    bool operator() (const int& a, const int& b) {
        return a>b;
    }
};

int solution(vector<int> scoville, int K) {
    make_heap(scoville.begin(), scoville.end(), greaters());
    while ((scoville.front() < K)&&(scoville.size()>1)) {
        int min1 = scoville.front(); 
        pop_heap(scoville.begin(), scoville.end(), greaters()); scoville.pop_back();
        int min2 = scoville.front(); 
        pop_heap(scoville.begin(), scoville.end(), greaters());  scoville.pop_back();
        int new_scovile = min1 + (min2*2); answer++;
        scoville.push_back(new_scovile); push_heap(scoville.begin(), scoville.end(), greaters());
    }
    
    if (scoville.front() < K) {return -1;}
    return answer;
}