#include <iostream>
using namespace std;

// 단순 재귀로 풀기에는 시간초과가 난다.
// 반복되는 작업을 줄이자.
int tile(int sum, int n)
{
    if (sum == n)
        return 1;
    else if (sum > n)
        return 0;

    sum = tile(sum + 1, n) + tile(sum + 2, n);
    return sum;
}

int main()
{
    int n, res;
    cin >> n;
    // 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수
    // 결국에는 n을 1과 2로 표현할 수 있는 방법의 수이다.(DP)
    res = tile(0, n) % 10007;
    // 10,007로 나눈 나머지
    cout << res << "\n";
}