/*
* File Name: rectangle.cpp
* Assignment: Lab 3 -- Templates and Multiple Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 26, 2025
*/


#include "rectangle.h"
#include <iostream>
#include <cstring>

using namespace std;

Rectangle::Rectangle(double x_coord, double y_coord, double sideA, double sideB, char* name) : Shape(x_coord, y_coord, name), 
    Square(x_coord, y_coord, sideA, name), side_b(sideB) {}

Rectangle::Rectangle(const Rectangle& other) : Shape(other), Square(other), side_b(other.side_b) {}

Rectangle& Rectangle::operator =(const Rectangle& rhs) {
    if (this != &rhs) {
        //Shape::operator = (rhs);
        Square::operator = (rhs);
        this->side_b = rhs.side_b;
    }
    return *this;
}

void Rectangle::setSide_b(double b) {
    this->side_b = b;
}
double Rectangle::getSide_b() {return this->side_b;}

double Rectangle::area() {
    return this->side_b * this->getSide_a();
}

double Rectangle::perimeter() {
    return (2*this->side_b) + (2*this->getSide_a());
}

void Rectangle::display() {
    cout << "Rectangle Name: " << this->getName() << endl;
    this->getOrigin().display();
    cout << "Side a: " << this->getSide_a() << endl;
    cout << "Side b: " << this->side_b << endl;
    cout << "Area: " << this->area() << endl;
    cout << "Perimeter: " << this->perimeter() << endl;
}
