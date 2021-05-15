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



