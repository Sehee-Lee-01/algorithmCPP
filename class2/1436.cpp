#include <iostream>
#include <string>
using namespace std;
int N, counter, title=665;
string temp;
int main() {
    scanf("%d", &N);
    while (counter!=N)
    {
       title++;
       temp=to_string(title);
       if (temp.find("666") != string::npos) {counter++;}
    }
    printf("%d", title);
}