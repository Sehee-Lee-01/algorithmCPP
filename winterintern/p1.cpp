#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string line)
{
    string answer = "";
    char curr_alpha;
    int i = 0;
    while (i < line.length())
    {
        curr_alpha = line[i];
        cout << "this " << curr_alpha << endl;

        if ((answer.length() > 0) && (curr_alpha == answer[answer.length() - 1]))
        {
            answer += '*';
            while (answer[answer.length() - 2] == line[i])
                i++;
        }
        else
        {
            answer += curr_alpha;
            cout << "add " << curr_alpha << endl;
            i++;
        }
    }
    return answer;
}

int main()
{
    string test = "aaabbbc";
    cout << solution(test) << endl;
}