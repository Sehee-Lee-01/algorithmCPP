#include <iostream>
#include <string>
using namespace std;
struct STACK_ELEMENT
{
    int data;
    STACK_ELEMENT * under_element;
    STACK_ELEMENT(int data=0, STACK_ELEMENT* under_element = nullptr):data(data), under_element(under_element) {}
};

class STACK
{
private:
    STACK_ELEMENT *top_element;
    int stack_size=0;
public:
    STACK() : stack_size(0), top_element(nullptr) {};

    void push(int X) {
        if (this->stack_size==0) {
            this->top_element = new STACK_ELEMENT(X);
            stack_size++;
        }
        else {
            STACK_ELEMENT * curr_top_element = this->top_element;
            this->top_element = new STACK_ELEMENT(X, curr_top_element);
            stack_size++;
        }   
    }

    void pop() {
        if (this->stack_size==0) {printf("-1\n");return;}
        if (this->stack_size==1) {
            printf("%d\n", this->top_element->data);
            this->top_element->under_element = nullptr;
            stack_size--;
        }
        else {
            printf("%d\n", this->top_element->data);
            STACK_ELEMENT * under_element = this->top_element->under_element;
            this->top_element = under_element;
            stack_size--;
        }
    }

    void size() {printf("%d\n", this->stack_size);}

    void empty() {
        if (this->stack_size==0) {printf("1\n");}
        else {printf("0\n");}    
    }

    void top() {
        if (this->stack_size==0) {printf("-1\n");}
        else {printf("%d\n", this->top_element->data);}
    }
};


int N, X;
string temp;
int main() {
    STACK test = STACK();
    scanf("%d\n", &N);
    for (int i=0; i<N; i++) {
        cin >> temp;
        if (temp == "push") {cin >> X; test.push(X);}
        if (temp == "pop") {test.pop();}
        if (temp == "size") {test.size();}
        if (temp == "empty") {test.empty();}
        if (temp == "top") {test.top();}
    }
}