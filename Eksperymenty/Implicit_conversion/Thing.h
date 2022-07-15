#ifndef EKSPERYMENTY_THING_H
#define EKSPERYMENTY_THING_H

#include<utility>

using namespace std;

class Thing{
private:
    int x, y;

public:
    Thing();
    //Thing(const pair<int, int>&);
    friend void getAttr(const Thing &th);
};

void getAttr(const Thing &th);


#endif EKSPERYMENTY_THING_H