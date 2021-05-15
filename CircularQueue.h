#ifndef MIDTERMPROJECT_CIRCULARQUEUE_H
#define MIDTERMPROJECT_CIRCULARQUEUE_H
#include <any>

class CircularQueue {

private:

    int rear, front;
    int size;
    std::any* elements;

public:

    explicit CircularQueue(int s);
    CircularQueue();
    ~CircularQueue();

    void enQueue(const std::any& value);
    std::any deQueue();
    bool isEmpty();
    bool isFull();
    int getNum();


};


#endif //MIDTERMPROJECT_CIRCULARQUEUE_H
