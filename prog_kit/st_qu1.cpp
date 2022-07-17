#include <string>
#include <vector>

using namespace std;
int prod_day, prod_num;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for (int i=0; i<progresses.size(); i++){
        int fin_day = 0, sum_progress = progresses[i];
        while(sum_progress < 100) {
            sum_progress += speeds[i]; 
            fin_day++;
        }
        
        if ((fin_day > prod_day)&&(i!=0)) {
            answer.push_back(prod_num); prod_num = 1;
            prod_day = fin_day;
        }
        else if (i==0) {prod_day = fin_day; prod_num =1; continue;}
        else {prod_num++;}
    }
    answer.push_back(prod_num);
    return answer;
}