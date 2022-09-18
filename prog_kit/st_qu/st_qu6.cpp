#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count_open = 0;
    for (auto element: s) {
        if (element == '(') {count_open++;}
        else {
            if ((element == ')')&&(count_open!=0)) {count_open--;}
            else {answer=false; break;}
        }
    }
    if (count_open!=0) {answer=false;}
    return answer;
}