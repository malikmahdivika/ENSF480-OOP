/*
* File Name: curvecut.h
* Assignment: Lab 3 -- Templates and Multiple Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 26, 2025
*/

#include "rectangle.h"
#include "circle.h"

class CurveCut : public Rectangle, public Circle {
    public:
        // ctor, copy ctor, overload assignment operator
        CurveCut(double x_coord, double y_coord, double sideA, double sideB, double rad, char* name);
        CurveCut(const CurveCut& other);
        CurveCut& operator =(const CurveCut &rhs);

        double area();
        double perimeter();
        void display();
};