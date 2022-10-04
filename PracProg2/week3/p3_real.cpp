#include <iostream>
using namespace std;
int T, N, M, A, B, O, D, C;

int main()
{
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d %d", &N, &M, &A, &B);
        int connect_array[N + 1][M - 1];
        // 나머지는 -1 초기화 하고 연결된 부분만 안에 최대 중량 넣기
        for (int j = 0; j < M; j++)
        {
            scanf("%d %d %d", &O, &D, &C);
        }
    }
}
