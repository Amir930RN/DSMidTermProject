#include <iostream>
#include "CounterStack.h"

using namespace std;

CounterStack::CounterStack(int s) {

    top = -1;
    size = s;
    elements = new any[s];
}

CounterStack::CounterStack() {

    top = -1;
    size = 100;
    elements = new any[100];

}

CounterStack::~CounterStack() { delete[] elements; }

bool CounterStack::isEmpty() { return (top < 0); }

bool CounterStack::isFull() { return top == size - 1; }

void CounterStack::push(const std::any &value) {

    if (isFull()) cout << "Stack Overflow";
    else elements[++top] = value;

}

int CounterStack::getNum() {

    if (isEmpty()) return 0;
    if (top==0) return 1;
    else return top+1;

}





