#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
# define MAX_N 10000
int N, counter, title_len=1; // len - 3
set<int> titles;
string temp, jongmal="666";
int main() {
    cin >> N;
    while (titles.size() < MAX_N)
    {
        for(int j=0; j<=title_len; j++) {
            for (int i=0; i<pow(10,title_len); i++) {
                temp = to_string(i);
                while (temp.length()==title_len-1){temp.insert(0,"0");}
                if (j == title_len) {temp += jongmal;}
                else {temp.insert(j,jongmal);}
                titles.insert(stoi(temp));
            cout << "nana? "<< temp << " " << j << endl;
            }
        }
        title_len++;
    }
    cout << "nana?" << endl;
    for (auto iter=titles.begin(); iter!=titles.end();iter++) {
        if (counter+1==N) {cout << *iter << " ";break;}
        counter++;
    }
}
