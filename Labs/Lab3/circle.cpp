/*
* File Name: circle.cpp
* Assignment: Lab 3 -- Templates and Multiple Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 26, 2025
*/

#include "circle.h"
#include <iostream>
#include <math.h>

using namespace std;

// constructor, copy ctor, etc.
Circle::Circle(double x_coord, double y_coord, double rad, char* name) : Shape(x_coord, y_coord, name), radius(rad) {};
Circle::Circle(const Circle& other) : Shape(other), radius(other.radius) {}
Circle& Circle::operator=(const Circle& rhs) {
    if (this != &rhs) {
        Shape::operator = (rhs);
        this-> radius = rhs.radius;
    }
    return *this;
     
}

// getter/setter
double Circle::get_radius() {return this->radius;}
void Circle::set_radius(double rad) {this->radius = rad;}

// utilities
double Circle::area() {
    double pi = 2 * acos(0.0);
    return pi * pow(this->radius, 2);
}

double Circle::perimeter() {
    double pi = 2 * acos(0.0);
    return 2 * pi * this->radius;
}

void Circle::display() {
    cout << "Circle name: " << this->getName() << endl;
    this->getOrigin().display();
    cout << "Radius: " << this->get_radius() << endl;
    cout << "Area: " << this->area() << endl;
    cout << "Perimeter: " << this->perimeter() << endl;
}