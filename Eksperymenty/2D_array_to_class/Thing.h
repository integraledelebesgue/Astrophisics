#ifndef THING_H
#define THING_H

#include<utility>
#include<iostream>

using namespace std;


class Thing{
private:
    int x, y;

public:
    Thing();
    Thing(int *const);
    friend void printAttr(const Thing &);
};

void printAttr(const Thing &);


#endif