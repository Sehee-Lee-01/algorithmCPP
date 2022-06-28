#include <iostream>
using namespace std;

double sum=0, max_score=0, temp; 
int subj_num;
int main() {
    scanf("%d", &subj_num);
    double score_array[subj_num];
    for (int i=0; i<subj_num; i++){
        scanf("%lf", &temp);
        score_array[i] = temp;
        if (temp > max_score) {max_score = temp;}
    }

    for (int i=0; i<subj_num; i++){
        sum += score_array[i]/max_score*100;
    }

    temp = sum/subj_num;
    printf("%.10lf\n", temp);
}