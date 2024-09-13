#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <cstring>
using namespace std;

#include "point.h"

class Human
{
protected:
    Point location; // Location of an object of Human on a Cartisian Plain
    char *name;     // Human's name
public:
    Human(const char *, double, double);

    char *get_name() { return name; }

    void set_name(char *);

    Point get_point() const { return location; }

    void display();
};

#endif