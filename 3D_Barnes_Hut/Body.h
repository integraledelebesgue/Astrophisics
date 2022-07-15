#ifndef BODY_H
#define BODY_H

#include<array>
#include<list>
#include "Vector.h"

using namespace std;


class Body{
private:
    double mass;
    Vector position;

public:
    Body();
    Body(const array<double, 4> &params);
    Body(const double &_mass, const Vector &_position);

    Vector getPosition();

    friend Body massCenter(const list<Body> &);
    friend short int qualify(const Body &body, const Vector &center);
    friend Vector graviForce(const Body &particle, const Body &source);
    friend bool operator ==(const Body &, const Body &);
};

Body massCenter(const list<Body> &);
short int qualify(const Body &body, const Vector &center);
Vector graviForce(const Body &particle, const Body &source);
bool operator ==(const Body &, const Body &);

#endif