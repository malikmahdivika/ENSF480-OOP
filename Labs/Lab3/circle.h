/*
* File Name: circle.h
* Assignment: Lab 3 -- Templates and Multiple Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 26, 2025
*/
#include "shape.h"

// virtual base class declaration for CurveCut multiple inheritance
class Circle : virtual public Shape {
    protected:
        double radius;
    public:
        Circle(double x_coord, double y_coord, double rad, char* name);     // constructor
        Circle(const Circle& other);                                        // copy constructor
        Circle& operator=(const Circle& rhs);                               // overload operator

        double get_radius();
        void set_radius(double rad); 

        double area();
        double perimeter();
        void display();
};