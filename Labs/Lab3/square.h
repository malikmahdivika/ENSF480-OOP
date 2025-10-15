/*
* File Name: square.h
* Assignment: Lab 3 -- Templates and Multiple Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 26, 2025
*/
#include "shape.h"

class Square : virtual public Shape {                                                   // inherits from Shape
    protected:
        double side_a;
    public:
        Square(double x_coord, double y_coord, double side, char* name);        // constructor sets coord as well
        Square(const Square& other);                                            // derived copy constructor (bc of side a)
        Square& operator=(const Square& rhs);                                   // overload assignment operator (same reason)
        // note: no destructor redefinition needed.

        double getSide_a();                                                     // side a getter
        void setSide_a(double a);

        // utilities
        virtual double area();
        double perimeter();
        void display();
};