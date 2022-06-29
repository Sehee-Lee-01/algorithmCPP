#include <iostream>
using namespace std;
int num, temp, min_num=1000000, max_num=-1000000;
int main() {
    scanf("%d", &num);
    for(int i=0; i<num; i++) {
        scanf("%d", &temp);
        if(temp>max_num) max_num=temp;
        if(temp<min_num) min_num=temp;
    }
    printf("%d %d", min_num, max_num);
}