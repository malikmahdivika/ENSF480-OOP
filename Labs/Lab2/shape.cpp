/*
* File Name: shape.cpp
* Assignment: Lab 2 -- Overloading Operators & Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 16, 2025
*/

#include "shape.h"
#include <iostream>
#include <cstring>

using namespace std;

    // constructor initializing values
    Shape::Shape(double x, double y, char* name): origin(x, y) {
        this->shapeName = new char[strlen(name) + 1];
        strcpy(this->shapeName, name);
    }



    Shape::~Shape() {                                                      // destructor for shapeName
        delete[] shapeName;
    }

    // getters
    const Point& Shape::getOrigin() const {
        return origin;
    }

    char* Shape::getName() const {                                               // return name copy to avoid memory leak
        char* name = new char[strlen(this->shapeName) + 1];
        strcpy(name, this->shapeName);
        return name;
    }

    // utilities
    void Shape::display() {
        cout << "Shape Name: " << this->shapeName << endl;
        this->origin.display();
    }

    double Shape::distance(Shape& other) {
       return this->origin.distance(other.getOrigin());
    }

    static double distance(Shape& the_shape, Shape& other) {
        return Point::distance(the_shape.getOrigin(), other.getOrigin());
    }

    void Shape::move(double dx, double dy) {
        this->origin.set_x(this->origin.get_x() + dx);
        this->origin.set_y(this->origin.get_y() + dy);
    }