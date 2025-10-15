/* File: basic_overloading.cpp
 * Author: Malik Mahdivika
 * Dev Date: Oct. 14, 2025
 * Examples for basic operator overloading (most binary operators essentially)
*/

// Counter example class
class Counter {
    private:
        int count;
    public:
        Counter(int initval);
        void increment(int increment_by);
        void print();
};

// Implementations
Counter::Counter(int initval) {
    count = initval;
}
void Counter::increment(int val) {
    count += val;
}

// Execution tests
int main() {
    Counter c1 = Counter(5);
    Counter c2 = Counter(5);
    c1.increment(3);

    
}