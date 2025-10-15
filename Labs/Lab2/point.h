/*
* File Name: point.h
* Assignment: Lab 2 -- Overloading Operators & Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 16, 2025
*/

#ifndef POINT_H
#define POINT_H

class Point {
    private:
        double x;
        double y;
        static int counter;
        int id;
    public:
        
        Point(double x_coord, double y_coord);                            // constructor with coordinate initialization

        void set_x(double newx);
        void set_y(double newy);
        double get_x() const;
        double get_y() const;
        int get_id() const;                                               // no setter for id, set in constructor
        

        int current_counter() const;                                      // returns current number of Point objects
        void display() const;                                             // displays formatted coordinates

        double distance(const Point& other) const;                        // returns distance from this Point to another
        static double distance(const Point& one, const Point& two);       // distance from two Point objects.
        
};

#endif
