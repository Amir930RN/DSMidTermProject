#include <iostream>
#include <any>
#include "CircularQueue.h"

using namespace std;

int main() {

    any o = 1;
    int i = any_cast<int>(o);

    CircularQueue q1 (4);
    CircularQueue q2;

    q1.enQueue(5);
    q1.enQueue(3);
    q1.enQueue(4);
    q1.enQueue(6);
    cout<<q1.isFull()<<" "<<q1.isEmpty()<<" "<<q2.isEmpty()<<" "<<q2.isFull()<<endl;
    cout<<any_cast<int>(q1.deQueue())<<endl;
    cout<<any_cast<int>(q1.deQueue())<<endl;
    cout<<q1.getNum();


    return 0;
}
