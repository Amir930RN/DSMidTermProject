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


