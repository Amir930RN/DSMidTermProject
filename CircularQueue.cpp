#include <iostream>
#include "CircularQueue.h"

using namespace std;

CircularQueue::CircularQueue(int s) {

    front = rear = -1;
    size = s;
    elements = new any[s];

}

CircularQueue::CircularQueue() {

    front = rear = -1;
    size = 100;
    elements = new any[100];

}

CircularQueue::~CircularQueue() {

    delete[] elements;

}

bool CircularQueue::isFull() {

    return (front == 0 && rear == size - 1) ||
           (rear == (front - 1) % (size - 1));

}

bool CircularQueue::isEmpty() {

    return front == -1;

}

void CircularQueue::enQueue(const any& value) {

    if (isFull()) cout<<"error! queue is full!"<<endl;

    /* Insert First Element */
    else if (front == -1)
    {
        front = rear = 0;
        elements[rear] = value;
    }

    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        elements[rear] = value;
    }

    else
    {
        rear++;
        elements[rear] = value;
    }

}

std::any CircularQueue::deQueue() {

    if (isEmpty())
    {
        cout<<"Queue is empty!"<<endl;
        return INT_MIN;
    }

    any data = elements[front];
    elements[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;

    return data;

}

int CircularQueue::getNum() {

   if( isEmpty() ) return 0;

   else if ( front==0 && rear==0 ) return 1;

   return rear+1;

}



