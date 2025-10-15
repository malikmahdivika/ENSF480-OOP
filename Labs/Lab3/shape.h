/*
* File Name: shape.h
* Assignment: Lab 3 -- Templates and Multiple Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 26, 2025
*/
#include "point.h"

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    protected:
        Point origin;
        char* shapeName;
    public:
        Shape(double x, double y, char* name);              // constructor with name and origin initialization
        Shape(const Shape& other);                          // copy constructor 
        virtual Shape& operator =(const Shape& rhs);        // overload assignment operator
        virtual ~Shape();                                   // destructor for shapeName

        const Point& getOrigin() const;                     // returns REFERENCE to origin which does not affect original
        char* getName() const;                              // returns name of the shape 
        virtual void display();                             // display function for shape name and origin coordinates

        double distance(Shape& other);
        static double distance(Shape& the_shape, Shape& other);
        void move(double dx, double dy);

        // virtual null function declarations
        virtual double area() {return 0;}
        virtual double perimeter() {return 0;}

};

#endif