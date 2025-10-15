/*
* File Name: rectangle.h
* Assignment: Lab 3 -- Templates and Multiple Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 26, 2025
*/

#include "square.h"

class Rectangle : public Square {
    protected:
        double side_b;
    public:
        Rectangle(double x_coord, double y_coord, double sideA, double sideB, char* name);
        Rectangle(const Rectangle& other);                                                      // copy ctor
        Rectangle& operator =(const Rectangle& rhs);                                                  // overload
        // no need for destructor, name is defined in shape which has a destructor

        void setSide_b(double b);
        double getSide_b();

        double area();
        double perimeter();
        void display();
};