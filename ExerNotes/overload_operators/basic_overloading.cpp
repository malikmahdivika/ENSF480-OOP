/* File: basic_overloading.cpp
 * Author: Malik Mahdivika
 * Dev Date: Oct. 14, 2025
 * Examples for basic operator overloading (most binary operators essentially)
*/
#include <iostream>

// Counter example class
class Counter {
    private:
        int count;
    public:
        Counter(int initval);
        void increment();
        void print();

        Counter operator +(Counter const &rhs);
};

// Implementations
Counter::Counter(int initval) : count(initval) {}
void Counter::increment() {count++;}
void Counter::print() {std::cout << count;}

Counter Counter::operator +(const Counter& rhs) {    // member-function operator overloading assumes the calling object is the LHS
    Counter newCounter(count + rhs.count);           // returns new Counter object, in this case assignment operator is NOT overloaded since
    return newCounter;                               // the only variable of Counter class is an integer primitive. ("Big 3" is not necessary)
}                                                    

// Execution tests
int main() {
    Counter c1 = Counter(5);
    Counter c2 = Counter(5);
    c1.increment();
    
    Counter c3 = c1 + c2;
    c3.print();
}