/*
* File Name: square.cpp
* Assignment: Lab 2 -- Overloading Operators & Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 16, 2025
*/


#include "square.h"
#include <math.h>
#include <iostream>

using namespace std;

Square::Square(double x_coord, double y_coord, double side, char* name) : Shape(x_coord, y_coord, name), side_a(side) {}

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
