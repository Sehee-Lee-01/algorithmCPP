// 가까운 사이의 두 점
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::count

using namespace std;
int main()
{
    string temp;
    getline(cin, temp);
    // 공백 수 찾기
    int n = count(temp.begin(), temp.end(), ' ') + 1;
    vector<int> seat_list;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        string temp2 = ""; // 번호 하나씩 입력 받고 push
        while (temp[index] != ' ')
        {
            temp2 += temp[index++];
        }
        index++;
        seat_list.push_back(stoi(temp2));
    }

    sort(seat_list.begin(), seat_list.end());

    int diff = seat_list.back() - seat_list.front();
    int seat_list_index = -1;
    for (int i = 0; i < seat_list.size() - 1; i++)
    {
        if (diff > (seat_list[i + 1] - seat_list[i]))
        {
            diff = seat_list[i + 1] - seat_list[i];
            seat_list_index = i;
        }
    }

    cout << seat_list[seat_list_index] << " " << seat_list[seat_list_index + 1];

    return 0;
}