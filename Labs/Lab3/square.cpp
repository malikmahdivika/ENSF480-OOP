/*
* File Name: square.cpp
* Assignment: Lab 3 -- Templates and Multiple Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 26, 2025
*/


#include "square.h"
#include <math.h>
#include <iostream>

using namespace std;

Square::Square(double x_coord, double y_coord, double side, char* name) : Shape(x_coord, y_coord, name), side_a(side) {}

// only need to set side a, other resources managed by Shape copy constructor
Square::Square(const Square& other) : Shape(other), side_a(other.side_a) {}

Square& Square::operator=(const Square& rhs) {
    if (this != &rhs) {
        Shape::operator = (rhs);
        this->side_a = rhs.side_a;
    }
    return *this;
}

double Square::getSide_a() {
    return this->side_a;
}

void Square::setSide_a(double a) {
    this->side_a = a;
}

double Square::area() {
    return pow(this->side_a, 2);
}
double Square::perimeter() {
    return 4 * this->side_a;
}
void Square::display() {
    cout << "Square Name: " <<this->getName() << endl;
    this->getOrigin().display();
    cout << "Side a: " << this->side_a << endl;
    cout << "Area: " << this->area() << endl;
    cout << "Perimeter: " << this->perimeter() << endl;
}
