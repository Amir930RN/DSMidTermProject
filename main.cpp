#include <iostream>
#include <any>


using namespace std;

int main() {

    any o = 1;
    int i = any_cast<int>(o);


    return 0;
}
