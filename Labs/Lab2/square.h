/*
* File Name: square.h
* Assignment: Lab 2 -- Overloading Operators & Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 16, 2025
*/
#include "shape.h"

class Square : public Shape {                                                   // inherits from Shape
    protected:
        double side_a;
    public:
        Square(double x_coord, double y_coord, double side, char* name);        // constructor sets coord as well
        double getSide_a();                                                     // side a getter
        void setSide_a(double a);

        // utilities
        double area();
        double perimeter();
        void display();
};