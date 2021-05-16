#include <iostream>
#include <any>
#include <vector>
#include "CircularQueue.h"

using namespace std;

string rotationalScheduling( const string& input );

int main() {

    any o = 1, oo =1;
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
    cout<<q1.getNum()<<endl;


    cout<<rotationalScheduling("A 5, B 2, C 1")<<endl;
    cout<<rotationalScheduling("A 2, B 3, C 2")<<endl;
    cout<<rotationalScheduling("Pr 3")<<endl;

    return 0;
}

string rotationalScheduling( const string& input ){

    vector <string> A;
    vector <string> names;
    vector <int> counts;

    //split the input with "," and add words to a list
    string del = ", ";
    int start = 0, end = input.find(del);
    while (end != -1) {
        A.push_back( input.substr(start, end - start) );
        start = end + del.size();
        end = input.find(del, start);
    }
    A.push_back(input.substr(start, end - start));

    //separate names and counts in two different lists
    del = " ";
    for (auto & i : A) {
        start = 0; end = i.find(del);
        names.push_back( i.substr(start, end - start) );
        start = end + del.size();
        end = input.find(del, start);
        counts.push_back( stoi( i.substr(start, end - start) ) );
    }

    //implementing function with CircularQueue
    int size = 0;
    for (int count : counts) size+=count;
    CircularQueue queue(size);
    int j=0;
    for (int i = 0; i < size ; ++i) {

        if ( counts[j]!=0 ){
            counts[j]--;
            queue.enQueue(names[j]);
        }
        else i--;

        if( j< A.size()-1 ) j++;
        else j=0;

    }

    string result;
    for (int i = 0; i < size ; ++i) {
        result+= any_cast<string> (queue.deQueue());
        result+= " ";
    }
    return result;

}