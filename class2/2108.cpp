#include <iostream>
#include <cmath>
#include <map>
using namespace std;
int N, temp, mean, curr_sum, median_val, median, mode, mode_count, mode_val, range;
double mean_float;
map<int, int> input;
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &temp);
        mean_float+=temp;
        if(input.find(temp)==input.end()) {input.insert({temp,1});}
        else {input.find(temp)->second++;}
    }
    mean=round(mean_float/N); median_val=N/2+1;
    range = input.rbegin()->first-input.begin()->first;
    for(auto &c : input) {
        if ((curr_sum<median_val)&&(curr_sum+c.second>=median_val)) {median=c.first;}
        curr_sum+=c.second;
    }
    for(auto &c : input) {
        // cout<<c.first<<" nana "<< mode << "**"<<mode_count<<endl;
        if (mode_val<c.second) {mode=c.first; mode_val=c.second; mode_count=1; continue;}
        if (mode_val==c.second) {if((++mode_count)==2) {mode=c.first; continue;}}
    }
    printf("%d\n%d\n%d\n%d\n", mean, median, mode, range);
}