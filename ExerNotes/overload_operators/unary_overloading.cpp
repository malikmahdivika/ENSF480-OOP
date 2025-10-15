/* File: unary_overloading.cpp
 * Author: Malik Mahdivika
 * Dev Date: Oct. 14, 2025
 * Examples for slightly more advanced operator overloading; unaries and less conventional operators like [] (which is binary).
*/
#include <iostream>
using namespace std;

// Tarot cards enum
enum Tarot {THE_FOOL, THE_TOWER, THE_HIEROPHANT, THE_LOVERS, STRENGTH, THE_HERMIT, THE_HIGH_PRIESTESS};

// Arcana example class
class Arcana {
    private:
        Tarot arcanaInHand[5];      // example array to test [] overloading
        int arcanaLifespan;
    public:
        Arcana(const Tarot hand[], int size, int arcanaNum);
        void print();

        Tarot& operator[](int index); // [] overloading
        Arcana& operator++();       // unary ++prefix (we can tell since it returns the reference aka new value)
        Arcana operator++(int);     // unary postfix++ (returns the old value, and since you can't overload on return type alone we have int arg)
};

// Constructor/Helper funcs
Arcana::Arcana(const Tarot hand[], int size, int num) : arcanaLifespan(num) {
    for (int i = 0; i < size; i++) {
        arcanaInHand[i] = hand[i];
    }
}
void Arcana::print() {
    cout << "Cards currently in hand: ";
    for (Tarot card : arcanaInHand) {
        cout << card << ", ";
    }
    cout << endl;
    printf("Lifespan of current Arcana: %d", arcanaLifespan);
}

// overloading << for print function
ostream& operator <<(ostream& os, Tarot card) {
    switch(card) {
        case THE_FOOL:  return os << "The Fool";
        case THE_TOWER:  return os << "The Tower";
        case THE_HIEROPHANT:  return os << "The Hierophant";
        case THE_LOVERS:    return os << "The Lovers";
        case STRENGTH:      return os << "Strength";
        case THE_HERMIT:    return os << "The Hermit";
        case THE_HIGH_PRIESTESS:   return os << "The High Priestess";
    }
}
// Modifiable non-constant overload
Tarot& Arcana::operator[](int index) {
    return arcanaInHand[index];
}
