#include <iostream>
#include "CounterStack.h"
#include <vector>

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

std::any CounterStack::pop() {

    if (isEmpty()) cout << "Stack Underflow";
    else{

        //create an unrepeated list from elements
        vector <any> values;
        bool flag;
        for (int i = 0; i < getNum() ; ++i) {
            flag = false;
            for (const auto & value : values) {
                if ( isEqual(value,elements[i]) ) flag = true;
            }
            if (!flag) values.push_back(elements[i]);

        }

        //create another list to count each of our values in stack
        int counts[values.size()];
        for (int i = 0; i < values.size() ; ++i) counts[i] = 0;

        for (int i = 0; i < values.size() ; ++i) {

            for (int j = 0; j < getNum() ; ++j) {

                if ( isEqual(values[i],elements[j]) ) counts[i]++;

            }

        }

        //find max in counts
        int max=counts[0] ;
        for (int count : counts) if ( max< count ) max = count;




    }

}


bool CounterStack::isEqual(const any &lhs, const any &rhs) {

    if (lhs.type() != rhs.type()) return false;

    if (lhs.type() == typeid(std::string)) return any_cast<std::string>(lhs) == any_cast<std::string>(rhs);

    if (lhs.type() == typeid(int)) return any_cast<int>(lhs) == any_cast<int>(rhs);

    if (lhs.type() == typeid(double)) return any_cast<double>(lhs) == any_cast<double>(rhs);

    if (lhs.type() == typeid(long)) return any_cast<long>(lhs) == any_cast<long>(rhs);

}





