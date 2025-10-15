/*
* File Name: Human.h
* Assignment: Lab 1 -- Review of C++ Fundamentals
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 14, 2025
*/

// original code missing .h files, here's Human.h
#ifndef HUMAN_H
#define HUMAN_H

#include "Point.h"
#include <cstring>

class Human {
    protected:
        Point location;     // Location of Human on a Cartesian plane
        char* name;         // Human's name

    public:
        Human(const char* nam, double x, double y);    // Constructor w/ defaults

        // Human handles dynamic resources, must use Rule of Three
        Human(const Human& other);              // copy constructor
        Human& operator=(const Human& rhs);     // overload assignment operator
        ~Human();                                      // destructor

        // getters/setters
        const char* getName() const;
        void setName(const char* name);
        Point getLocation() const;

        void display() const;

};

#endif