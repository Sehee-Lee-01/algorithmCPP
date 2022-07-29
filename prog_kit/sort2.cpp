#include <string>
#include <algorithm>
#include <vector>

using namespace std;
// sort rule
bool cmp (string a, string b) {
    // if first letter same
    if ((a[0]==b[0])&&(a.length()!=b.length())) {
        // seek minimum length
        int min_length;
        if (a.length()>b.length()) {min_length = b.length();} 
        else {min_length = a.length();}
        // while [i(0~min_length-1)] is same
        for (int i=0; i<min_length;i++) {
            if (a[i]>b[i]) {return true;}
            if (a[i]<b[i]) {return false;}
        }
        // if same from [0]~[min_length-1]
        string sub_string = ""; // [min_length~-1]
        if (min_length == b.length()) {
            for (int i=min_length; i<a.length(); i++) {sub_string+=a[i];}
            return cmp(sub_string,b);
        }
        else{
            for (int i=min_length; i<b.length(); i++) {sub_string+=b[i];}
            return cmp(a,sub_string);
        }
    }
    else {return a>b;}
}

string solution(vector<int> numbers) {
    string answer = "";
    
    // int to string
    vector<string> st_numbers;
    for (auto element: numbers) {st_numbers.push_back(to_string(element));}
    
    // sort string by cmp
    sort(st_numbers.begin(), st_numbers.end(), cmp);
    
    // make answer
    for (auto element : st_numbers) {answer+= element;}
    if (answer[0]=='0') {answer="0";}
    return answer;
}