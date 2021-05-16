#ifndef MIDTERMPROJECT_COUNTERSTACK_H
#define MIDTERMPROJECT_COUNTERSTACK_H

#include <any>

class CounterStack {

private:

    int top;
    std::any * elements;
    int size;

public:

    CounterStack ( int s);
    CounterStack ( );
    ~CounterStack ( );

    void push(const std::any& value);
    std::any pop();
    bool isEmpty();
    bool isFull();
    int getNum();

};


#endif //MIDTERMPROJECT_COUNTERSTACK_H
