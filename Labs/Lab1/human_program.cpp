/*
* File Name: human_program.cpp
* Assignment: Lab 1 -- Review of C++ Fundamentals
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 14, 2025
*/

#include <cstring>
#include <iostream>
#include <assert.h>


using namespace std;
class Point{
private:
    double x;     // x coordinate of a location on Cartesian Plain
    double y;     // y coordinate of a location on Cartesian Plain
public:
    Point(double a =0, double b =0): x(a), y(b) {}  // constructor
    
    double get_x() const {return x;}                       // const promise
    double get_y() const {return y;}                       // const promise
    
    void set_x(double a) { x = a;};
    void set_y(double a) { y = a;};
};

class Human {
protected:
    Point location;   // Location of an object of Human on a Cartisian Plain
    char *name;       // Human's name
public:
    
    // Constructor
    Human(const char* nam="", double x=0, double y=0): name(new char[strlen(nam)+1]) {
        strcpy(this ->name, nam);
        location.set_x(x);
        location.set_y(y);
    }
    
    // copy constructor
    Human(const Human& other) {
        location = other.location;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    // overload assignment operator
    Human& operator=(Human& rhs) {
        if(this != &rhs) {
            delete [] name;
            name = new char[strlen(rhs.name) + 1];
            assert(name != NULL);
            strcpy(name, rhs.name);
        }
        return *this;
    }

    // destructor
    ~Human() {
        delete [] name;
        name = NULL;
    }

    char* get_name() const {return name;}           // constant promise
            
    void set_name(const char* name) {               // passed name should be const to avoid mutation
        delete [] this->name;                       // must delete before reassigning          
        this->name = new char[strlen(name)+1];        
        strcpy(this ->name, name);
    }
   
    Point get_point() const {return location;}      // constant promise
    
    void display() {                      
        cout << "Human Name: " << name << "\nHuman Location: "
        << location.get_x() << " ,"
        << location.get_y() << ".\n" << endl;
    }
};



#include <iostream>

int main(int argc, char **argv)
{
	double x = 2000, y = 3000;
	Human h("Ken Lai", x , y); 
    h.display();
	return 0;
}

