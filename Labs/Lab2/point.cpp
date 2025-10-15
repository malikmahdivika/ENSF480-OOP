/*
* File Name: point.cpp
* Assignment: Lab 2 -- Overloading Operators & Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 16, 2025
*/

#include "point.h"
#include <iostream>
#include <cmath> 

using namespace std;

// define the static counter declared in the header
int Point::counter = 1000;

// constructor
Point::Point(double x_coord, double y_coord) : x(x_coord), y(y_coord), id(++counter) {}

// setters/getters
void Point::set_x(double newx) { this->x = newx; }
void Point::set_y(double newy) { this->y = newy; }
double Point::get_x() const { return this->x; }
double Point::get_y() const { return this->y; }
int Point::get_id() const { return this->id; }

int Point::current_counter() const {
    return Point::counter - 1000;
}

void Point::display() const {
    cout << "X-coordinate: " << this->get_x() << endl;
    cout << "Y-coordinate: " << this->get_y() << endl;
}

double Point::distance(const Point& other) const {
    double radicand_x = other.get_x() - this->get_x();
    double radicand_y = other.get_y() - this->get_y();
    return sqrt(pow(radicand_x, 2) + pow(radicand_y, 2));
}

double Point::distance(const Point& one, const Point& two) {
    double radicand_x = two.get_x() - one.get_x();
    double radicand_y = two.get_y() - one.get_y();
    return sqrt(pow(radicand_x, 2) + pow(radicand_y, 2));
}
