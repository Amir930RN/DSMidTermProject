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

    delete elements;

}

bool CircularQueue::isFull() {

    return (front == 0 && rear == size - 1) ||
           (rear == (front - 1) % (size - 1));

}

bool CircularQueue::isEmpty() {

    return !isFull();

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



