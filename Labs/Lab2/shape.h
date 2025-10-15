/*
* File Name: shape.h
* Assignment: Lab 2 -- Overloading Operators & Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 16, 2025
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
        ~Shape();                                           // destructor for shapeName

        const Point& getOrigin() const;                     // returns REFERENCE to origin which does not affect original
        char* getName() const;                              // returns name of the shape 
        void display();                                     // display function for shape name and origin coordinates

        double distance(Shape& other);
        static double distance(Shape& the_shape, Shape& other);
        void move(double dx, double dy);

};

#endif