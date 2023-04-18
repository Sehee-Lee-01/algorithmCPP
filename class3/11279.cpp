#include <iostream>
using namespace std;
#define MAX 100000
int max_hip[MAX + 1], cnt = 0;

void swap(int a, int b)
{
    int t = max_hip[a];
    max_hip[a] = max_hip[b];
    max_hip[b] = t;
}

void from_root(int idx)
{
    if (idx * 2 + 1 <= cnt)
    {
        int max_chd = idx * 2 + 1;
        if (max_hip[max_chd] < max_hip[idx * 2])
            max_chd = idx * 2;

        if (max_hip[idx] < max_hip[max_chd])
        {
            swap(idx, max_chd);
            from_root(max_chd);
        }
    }
    else if (idx * 2 <= cnt)
    {
        if (max_hip[idx] < max_hip[idx * 2])
        {
            swap(idx, idx * 2);
            from_root(idx * 2);
        }
    }
}

int pop()
{
    if (cnt < 1)
        return 0;
    int root = max_hip[1];
    max_hip[1] = max_hip[cnt--];
    from_root(1);

    return root;
}

void from_leaf(int idx)
{
    if (idx <= 1)
        return;
    else if (max_hip[idx / 2] < max_hip[idx])
    {
        swap(idx / 2, idx);
        from_leaf(idx / 2);
    }
}

void push(int temp)
{
    max_hip[++cnt] = temp; // push
    from_leaf(cnt);
}

int main()
{
    int N, temp;
    cin >> N;
    int res[N + 1], res_cnt = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        if (temp == 0)
            res[res_cnt++] = pop();
        else
            push(temp);
    }

    for (int i = 0; i < res_cnt; i++)
        cout << res[i] << "\n";
    return 0;
}