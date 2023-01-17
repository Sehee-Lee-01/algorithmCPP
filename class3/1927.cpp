#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
private:
    int size = 0;
    vector<int> array; // 루트노드의 주소는 1;

public:
    MinHeap()
    {
        array.push_back(0); // 인덱스가 1부터 시작
    }

    void swap(int a, int b)
    {
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }

    void top_down(int idx) // 자식들 중 가장 작은 것과 스위치
    {
        if ((idx * 2 + 1) < array.size()) // 오른 자식 체크
        {
            int min_child;
            if (array[idx * 2] < array[idx * 2 + 1]) // 왼자식이 작은 경우
                min_child = (idx * 2);
            else // 오른 자식이 작거나 같은 경우
                min_child = (idx * 2 + 1);

            if (array[min_child] < array[idx]) // 부모보다 작을 때
            {
                swap(idx, min_child);
                top_down(min_child);
            }
        }
        else if ((idx * 2) < array.size()) // 왼 자식(==마지막 노드)만 있을 경우
            if (array[idx * 2] < array[idx])
                swap(idx, idx * 2);

        // 자식이 없는 경우는 중지
    }

    void delete_element() // 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
    {
        if (size == 0) // 배열이 비어 있는 경우
            cout << "0\n";
        else
        {
            // 루트노드 값을 출력한다.
            cout << array[1] << "\n";

            // 루트 노드와 가장 마지막 노드를 스위칭 한다.
            swap(1, array.size() - 1);

            // 마지막 노드(루트 노드였던 것)를 지운다.
            array.pop_back();
            size--;

            // 루트노드 자리에 들어온 마지막 노드를 자식 노드들을 보며 자식 중 가장 작은 것을 자기 자신과 바꾼다.(끝까지)
            top_down(1);
        }
    }

    void bottom_up(int idx)
    {
        if ((idx != 1) && (array[idx] < array[idx / 2])) // 부모와 비교후 부모보다 작으면 스위치
        {
            swap(idx / 2, idx);
            bottom_up(idx / 2);
        }
    }

    void add_element(int element) // 배열에 자연수 x를 넣는다.
    {
        // 배열의 마지막 부분에 넣는다.
        array.push_back(element);
        size++;

        // 부모 노드와 비교하며 계속 스위칭한다.
        bottom_up(array.size() - 1);
    }
};

int main()
{
    int N, X;
    cin >> N;

    MinHeap min_heap = MinHeap();

    for (int i = 0; i < N; i++)
    {
        cin >> X;

        if (X == 0)
            min_heap.delete_element();
        else
            min_heap.add_element(X);
    }
}