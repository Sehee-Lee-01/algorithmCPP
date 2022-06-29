#include <iostream>
using namespace std;
int testcase, temp_num;
string temp_st;
int main() {
    scanf("%d", &testcase);
    for (int i=0; i<testcase; i++){
        cin >> temp_num >> temp_st;
        for (int j=0; j<temp_st.length(); j++)  {
            for(int k=0; k<temp_num; k++) {cout << temp_st[j];}
        }
        cout << endl;
    }
}