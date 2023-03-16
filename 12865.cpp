#include <iostream>
#include <algorithm>
using namespace std;

int N, K, W[101], V[101]; // N<=100
int dp[101][100001];      // [N][K] 칸의 각 경우의 최대 가치 기록

// 1. 재귀로 포함하는 경우, 안포함하는 경우를 일일이 찾아본다.
int recul_v(int i, int total_w)
{
    if (i == N) // 물건 탐색이 다 끝났을 경우
        return 0;

    // 1) 해당 인덱스 물건을 포함하는 경우 탐색
    int inc_v = 0;
    if (total_w + W[i] <= K)
        inc_v = V[i] + recul_v(i + 1, total_w + W[i]);

    // 2) 해당 인덱스 물건을 안 포함하는 경우 탐색
    int uninc_v = recul_v(i + 1, total_w);

    // ※ 매 번 중복 연산을 하기 때문에 과부하 발생
    return max(inc_v, uninc_v);
}

// 2. DP로 값들을 캐싱(메모라이징)하는 경우
int dp_v(int i, int total_w)
{
    if (i == N)
        return 0;

    if (dp[i][total_w] >= 0) // 이미 연산이 되어있다면
        return dp[i][total_w];

    // 아니라면 연산해서 메모라이징
    int inc_v = 0;
    if (total_w + W[i] <= K)
        inc_v = V[i] + dp_v(i + 1, total_w + W[i]);

    int uninc_v = dp_v(i + 1, total_w);

    dp[i][total_w] = max(inc_v, uninc_v);

    // ※ 메모라이징으로 더 효율적으로 연산 가능
    return dp[i][total_w];
}

int main()
{

    cin >> N >> K;

    for (int i = 0; i < N; i++) // 가치가 0인 경우도 있어서
        for (int j = 0; j < K; j++)
            dp[i][j] = -1;

    for (int i = 0; i < N; i++)
        cin >> W[i] >> V[i];

    // cout << recul_v(0, 0) << "\n"; // 1. 재귀
    cout << dp_v(0, 0) << "\n"; // 2. DP

    return 0;
}