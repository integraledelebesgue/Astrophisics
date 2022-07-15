#ifndef THING_H
#define THING_H

#include<utility>
#include<string>

using namespace std;

class Thing{
private:
    int x, y;

public:
    Thing();
    Thing(const pair<int, int> &);
    friend void printAttr(const Thing &);
};

void printAttr(const Thing &th);

#endif