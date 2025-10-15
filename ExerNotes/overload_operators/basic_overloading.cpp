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
        friend std::ostream& operator << (std::ostream& os, Counter const &counter);    // friend declaration
};

// Helper funcs
Counter::Counter(int initval) : count(initval) {}
void Counter::increment() {count++;}
void Counter::print() {std::cout << count << std::endl;}

// operator overloads
Counter Counter::operator +(const Counter& rhs) {    // member-function operator overloading assumes the calling object is the LHS
    Counter newCounter(count + rhs.count);           // returns new Counter object, in this case assignment operator is NOT overloaded since
    return newCounter;                               // the only variable of Counter class is an integer primitive. ("Big 3" is not necessary)
}
// To overload <<, it MUST be non-member to Counter and we can call the method a friend to Counter for ease of access to counter fields
std::ostream& operator << (std::ostream& os, Counter const &counter) {
    return os << counter.count << std::endl;
}                                                    

// Execution tests
int main() {
    Counter c1 = Counter(5);
    Counter c2 = Counter(5);
    c1.increment();
    std::cout << "c1 after increment: ";            // should be 6
    c1.print();
    std::cout << std::endl;
    
    Counter c3 = c1 + c2;
    std::cout << "c3 after overloaded \"+\" call: ";
    std::cout << c3 << std::endl;                   // use overloaded << operator, should be 11
}