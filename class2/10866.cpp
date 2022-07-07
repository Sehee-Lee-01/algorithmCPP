#include <iostream>
#include <string>
using namespace std;
int N, temp_X;
string temp;

struct element_decque {
    int data;
    element_decque* next_element;
    element_decque(int data=0, element_decque* next_element=nullptr) : data(data), next_element(next_element) {};
};

class deque {
private:
    element_decque * start;
    int deque_size = 0;
public:
    deque(const int data) {
        start = new element_decque();
    }
    void push_front(const int data) {
        if(deque_size==0) {this->start->data=data;}
        else {
            element_decque *second_element = new element_decque(this->start->data, this->start->next_element);
            this->start->data = data;
            this->start->next_element = second_element;
        }
        this->deque_size++;
    }
    void push_back(const int data) {
        if(deque_size==0) {this->start->data=data;}
        else {
            element_decque * back_element = new element_decque(data);
            element_decque * element_ptr = this->start;
            while (element_ptr->next_element != nullptr) {
                element_ptr = element_ptr->next_element;
            }
            element_ptr->next_element = back_element;
        }
        this->deque_size++;
    }
    void pop_front() {
        if (this->deque_size==0) {cout<<-1<<"\n";} 
        else {
            cout<<this->start->data<<"\n";
            if (this->deque_size>1) {this->start = this->start->next_element;}
            this->deque_size--;
        }
    }
    void pop_back() {
        if (this->deque_size==0) {cout<<-1<<"\n";} 
        else {
            element_decque * element_ptr = this->start; 
            element_decque * before_element_ptr = nullptr;
            if (this->deque_size>1) {
                while (element_ptr->next_element != nullptr) {
                    before_element_ptr = element_ptr;
                    element_ptr = element_ptr->next_element;
                }
            } else {before_element_ptr = element_ptr;}
            cout<<element_ptr->data<<"\n";
            before_element_ptr->next_element = nullptr;
            this->deque_size--;
        }
    }
    void size() {cout<<this->deque_size<<"\n";}
    void empty() {
        if(this->deque_size==0) {cout<<1<<"\n";} else {cout<<0<<"\n";}
    }
    void front() {
        if (deque_size==0) {cout<<-1<<"\n";} else {cout <<this->start->data<<"\n";}
    }
    void back() {
        if (deque_size==0) {cout<<-1<<"\n";} 
        else {
            element_decque * element_ptr = this->start;
            while (element_ptr->next_element != nullptr) {
                element_ptr = element_ptr->next_element;
            }
            cout <<element_ptr->data<<"\n";
        }
    }
};

int main() {
    scanf("%d", &N);
    deque test_deque(0);
    for(int i=0; i<N; i++) {
        cin >> temp;
        if(temp=="push_front") {cin >> temp_X; test_deque.push_front(temp_X);}
        if(temp=="push_back") {cin >> temp_X; test_deque.push_back(temp_X);}
        if(temp=="pop_front") {test_deque.pop_front();}
        if(temp=="pop_back") {test_deque.pop_back();}
        if(temp=="size") {test_deque.size();}
        if(temp=="empty") {test_deque.empty();}
        if(temp=="front") {test_deque.front();}
        if(temp=="back") {test_deque.back();}
    }
}