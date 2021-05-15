#include <iostream>
#include <any>
#include "CircularQueue.h"

using namespace std;

int main() {

    any o = 1;
    int i = any_cast<int>(o);

    CircularQueue q1 (4);

    q1.enQueue(5);
    q1.enQueue(3);
    cout<<q1.getNum();


    return 0;
}
