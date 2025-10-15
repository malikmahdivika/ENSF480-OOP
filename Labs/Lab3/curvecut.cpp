/*
* File Name: curvecut.cpp
* Assignment: Lab 3 -- Templates and Multiple Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 26, 2025
*/

#include "curvecut.h"
#include <iostream>
#include <math.h>

using namespace std;

// ctors, etc.
CurveCut::CurveCut(double x_coord, double y_coord, double sideA, double sideB, double rad, char* name) : Shape(x_coord, y_coord, name),
    Rectangle(x_coord, y_coord, sideA, sideB, name), Circle(x_coord, y_coord, rad, name) {
        if (rad > sideA || rad > sideB) {
            cout << "Error: radius of CurveCut must be <= both sides of the rectangle." << endl;
            abort();
        }
    }
CurveCut::CurveCut(const CurveCut& other) : Shape(other), Rectangle(other), Circle(other) {}
CurveCut& CurveCut::operator =(const CurveCut& rhs) {
    if (this != &rhs) {
        Shape::operator = (rhs);
        Rectangle::operator = (rhs);
        Circle::operator = (rhs);
    }
    return *this;
}

// utilities
double CurveCut::area() {
    // calculate respective areas first
    double rect_area = Rectangle::area();
    double circ_area = Circle::area() / 4.0;

    // curvecut subtracts 1/4 of the circle's area from rectangle
    return rect_area - circ_area;
}

double CurveCut::perimeter() {
    // perimeter of curvecut removes 2r from rectangle perimeter, and adds 1/4 of the circle's perimeter in its stead
    double rect_perim = Rectangle::perimeter() - (2 * this->radius);
    double circ_perim = Circle::perimeter() / 4;

    return rect_perim + circ_perim;
}

void CurveCut::display() {
    cout << "CurveCut Name: " << this->getName() << endl;
    this->getOrigin().display();
    cout << "Width: " << this->getSide_b() << endl;
    cout << "Length: " << this->getSide_a() << endl;
    cout << "Radius of the cut: " << this->get_radius() << endl;
}