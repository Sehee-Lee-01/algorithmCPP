#include <iostream>
using namespace std;

// 단순 재귀가 아닌 기억을 하면서 풀자
unsigned int memo[100];
unsigned int tile(unsigned int _n)
{
    if (_n == 1 || _n == 0)
        return 1;

    if (memo[_n] != 0)
        return memo[_n];

    memo[_n] = (tile(_n - 1) + tile(_n - 2)) % 10007; // 오버플로우 방지
    return memo[_n];
}

int main()
{
    unsigned n, res;
    cin >> n;
    // 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수
    // 결국에는 n을 1과 2로 표현할 수 있는 방법의 수이다.(DP)
    // res = tile(n) % 10007; // 오버 플로우 발생 가능성 있다.
    res = tile(n);
    // 10,007로 나눈 나머지
    cout << res << "\n";
}