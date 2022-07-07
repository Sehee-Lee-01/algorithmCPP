#include <iostream>
#include <string>
using namespace std;

struct Queue_element {
    int data;
    Queue_element * next_element;
    Queue_element(int data=0, Queue_element * next_element=nullptr) : data(data), next_element(next_element) {}
};

class Queue {
private:
    Queue_element * start;
    int Queue_size=0;
public:
    Queue(const int data) {
        this->start = new Queue_element();
    }
    void push(const int X) {
        if(Queue_size==0) {this->start->data = X;}
        else {
            auto element = this->start;
            while (element->next_element!=nullptr) {
                element = element->next_element;
            }
            element->next_element = new Queue_element(X);
        }
        this->Queue_size++;
    }
    void pop() {
        if (Queue_size==0) {printf("-1\n");}
        else {
            printf("%d\n", this->start->data);
            if (Queue_size>1) {this->start = this->start->next_element;}
            this->Queue_size--;
        }
    }
    void size() {printf("%d\n", this->Queue_size);}
    void empty() {
        if(this->Queue_size==0) {printf("1\n");} else {{printf("0\n");}}
    }
    void front() {
        if (this->Queue_size==0) {printf("-1\n");}
        else {printf("%d\n", this->start->data);}
    }
    void back() {
        if (this->Queue_size==0) {printf("-1\n");}
        else {
            auto element = this->start;
            while (element->next_element!=nullptr) {
                element = element->next_element;
            }
            printf("%d\n", element->data);
        }
    }
};

int N, X;
string command;
int main() {
    cin >> N;
    Queue test(0);
    for (int i=0; i<N; i++) {
        cin >> command;
        if (command == "push") {cin >> X; test.push(X);}
        if (command == "pop") {test.pop();}
        if (command == "size") {test.size();}
        if (command == "empty") {test.empty();}
        if (command == "front") {test.front();}
        if (command == "back") {test.back();}
    }
}