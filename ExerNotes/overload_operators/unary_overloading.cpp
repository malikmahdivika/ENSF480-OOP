/* File: unary_overloading.cpp
 * Author: Malik Mahdivika
 * Dev Date: Oct. 14, 2025
 * Examples for slightly more advanced operator overloading; unaries and less conventional operators like [] (which is binary).
*/
#include <iostream>
#include <string>
using namespace std;

// Tarot cards enum
enum Tarot {THE_FOOL, THE_TOWER, THE_HIEROPHANT, THE_LOVERS, STRENGTH, THE_HERMIT, THE_HIGH_PRIESTESS};

// Arcana example class
class Arcana {
    private:
        Tarot arcanaInHand[5];      // example array to test [] overloading
        int arcanaLifespan;
    public:
        Arcana(const Tarot hand[], int arcanaNum);
        string toString(Tarot card);
        void print();

        Tarot& operator[](int index); // [] overloading
        Arcana& operator++();       // unary ++prefix (we can tell since it returns the reference aka new value)
        Arcana operator++(int);     // unary postfix++ (returns the old value, and since you can't overload on return type alone we have int arg)
};

// Constructor/Helper funcs
Arcana::Arcana(const Tarot hand[], int num) : arcanaLifespan(num) {
    for (int i = 0; i < 5; i++) {
        arcanaInHand[i] = hand[i];
    }
}
void Arcana::print() {
    cout << "Cards currently in hand: ";
    for (Tarot card : arcanaInHand) {
        cout << toString(card) << ", ";
    }
    cout << endl;
    printf("Lifespan of current Arcana: %d\n", arcanaLifespan);
}
// string function
string Arcana::toString(Tarot card) {
    switch (card) {
        case THE_FOOL:          return "The Fool";
        case THE_TOWER:         return "The Tower";
        case THE_HIEROPHANT:    return "The Hierophant";
        case THE_LOVERS:        return "The Lovers";
        case STRENGTH:          return "Strength";
        case THE_HERMIT:        return "The Hermit";
        case THE_HIGH_PRIESTESS:return "The High Priestess";
        default:                return "Unknown Card";
    }
}
// Modifiable non-constant overload
Tarot& Arcana::operator[](int index) {
    return arcanaInHand[index];
}
Arcana& Arcana::operator++() {
    ++arcanaLifespan;           // increment first
    return *this;      // return the updated object
}
// Postfix ++ (e.g., x++)
Arcana Arcana::operator++(int) {
    Arcana temp = *this;  // make a copy (old value)
    ++arcanaLifespan;               // then increment
    return temp;           // return old value
}

int main() {
    Tarot hand[] = {THE_FOOL, THE_HIGH_PRIESTESS, STRENGTH, THE_FOOL, THE_LOVERS};
    Arcana ar = Arcana(hand, 2);
    Arcana ar1 = Arcana(hand, 2);
    cout << "Initial state" << endl;
    ar.print();

    ar[0] = THE_HIEROPHANT;
    cout << "After hand[0] modification" << endl;
    ar.print();

    // comparing post/pre-fix incrementors
    for (int i = 0; i < 2; i++) {
        ar++;
        ar.print();
        ++ar1;
        ar1.print();
    }
}