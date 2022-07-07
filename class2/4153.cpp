#include <iostream>
#include <set>
using namespace std;
int a=1,b=1,c=1;
set<int> triangle;
int main() {
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if ((a==0)&&(b==0)&&(c==0)) {break;}
        triangle.insert(a);
        triangle.insert(b);
        triangle.insert(c);
        int right_one=0, left_two=0;
        auto iter = triangle.begin();
        left_two+=(*iter)*(*iter++);
        left_two+=(*iter)*(*iter++);
        right_one+=(*iter)*(*iter);
        if (right_one==left_two) {printf("right\n");}
        else {printf("wrong\n");}
        triangle.clear();
    }
    
}