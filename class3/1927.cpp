// 운영체제에서 배운 IO 때문인가,,
// 답을 배열에 한꺼번에 저장해뒀다가 나중에 몰아서 출력하는 것이 더 빠르다!
#include <iostream>
using namespace std;

#define MAX 100002

int cnt = 0;
int nodes[MAX];

void swap_node(int a, int b)
{
    int temp = nodes[a];
    nodes[a] = nodes[b];
    nodes[b] = temp;
}

void seek_from_par(int loc)
{
    if (loc * 2 + 1 <= cnt) // 자식이 두 개 다 있을 때
    {
        int min = loc * 2 + 1;
        if (nodes[min] > nodes[loc * 2])
            min = loc * 2;

        if (nodes[min] < nodes[loc])
        {
            swap_node(min, loc);
            seek_from_par(min);
        }
    }
    else if (loc * 2 <= cnt) // 자식이 한 개 있을 때
    {
        if (nodes[loc * 2] < nodes[loc])
        {
            swap_node(loc * 2, loc);
            seek_from_par(loc * 2);
        }
    }
}

int min_pop()
{
    if (cnt < 1) // 원소가 없을 때
        return 0;

    // 원소개 하나라도 있을 때
    int min = nodes[1];
    nodes[1] = nodes[cnt--];

    seek_from_par(1);

    return min;
}

void seek_form_chd(int a)
{
    if (a < 2)
        return;

    if (nodes[a] < nodes[a / 2])
    {
        swap_node(a, a / 2);
        seek_form_chd(a / 2);
    }
}

void min_push(int x)
{
    nodes[++cnt] = x;
    seek_form_chd(cnt);
}

int main()
{
    int N;
    cin >> N;
    int ans_num = 0, ans[N];

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        if (x < 1)
            ans[ans_num++] = min_pop();
        else
            min_push(x);
    }

    for (int i = 0; i < ans_num; i++)
        cout << ans[i] << "\n";

    return 0;
}