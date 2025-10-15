/*
* File Name: rectangle.cpp
* Assignment: Lab 2 -- Overloading Operators & Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 16, 2025
*/


#include "rectangle.h"
#include <iostream>
#include <cstring>

using namespace std;

Rectangle::Rectangle(double x_coord, double y_coord, double sideA, double sideB, char* name) : Square(x_coord, y_coord, sideA, name), side_b(sideB) {};

Rectangle::Rectangle(const Rectangle& other) : Square(other.getOrigin().get_x(), other.getOrigin().get_y(), other.side_a, other.getName()) {
    this->setSide_b(other.side_b);
}

Rectangle& Rectangle::operator =(Rectangle& rhs) {
    if (this != &rhs) {
        this ->setSide_a(rhs.side_a);
        this ->setSide_b(rhs.side_b);
        this ->move(-this->getOrigin().get_x(),-this->getOrigin().get_y());
        this ->move(rhs.getOrigin().get_x(), rhs.getOrigin().get_y());
        delete [] shapeName;
        this ->shapeName = new char[strlen(rhs.getName()) + 1];
        strcpy(this->shapeName, rhs.getName());
    }
    return *this;
}

void Rectangle::setSide_b(double b) {
    this->side_b = b;
}

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
