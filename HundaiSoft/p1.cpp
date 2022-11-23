// 이미지 압축
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void imgzip(int start_y, int start_x, int end_y, int end_x, const vector<vector<int>> &img)
{
    if (end_y == start_y)
    {
        cout << img[start_y][end_y];
        return;
    }
    int mul = 1;
    int iszero = 0;
    for (int i = 0; i < img.size(); i++)
    {
        for (int j = 0; j < img.size(); j++)
        {
            sum *= img[i][j];
        }
        if (sum != 0 || sum)
    }
}
int main()
{
    int n;
    cin >> n;

    // 입력받기
    string temp;
    vector<vector<int>> image;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            image[i][j] = temp[j];
        }
    }
    imgzip(0, 0, n - 1, n - 1, image);
    return 0;
}