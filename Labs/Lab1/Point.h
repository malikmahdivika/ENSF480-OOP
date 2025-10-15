//Point header file

/*
* File Name: Point.h
* Assignment: Lab 1 -- Review of C++ Fundamentals
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 14, 2025
*/

#ifndef POINT_H
#define POINT_H

class Point {
    private:
        double x;       // x on Cartesian plane
        double y;       // y on Cartesian plane
    public:
        Point(double a = 0, double b = 0);      // constructor

        //setters/getters
        double getX() const;
        double getY() const;

        double setX(double a);
        double setY(double b);
};

#endif