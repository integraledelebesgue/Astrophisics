#ifndef BODY_H
#define BODY_H

#include<array>

using namespace std;


class Body{
private:
    double mass;
    array<double, 3> position;

public:
    Body();
    Body(double *const);
    Body(const array<double, 4> &);

    friend array<double, 3> gravitationForce(const Body &, const Body &);
    friend int qualifyBody(const Body &, const array<double, 3> &);
};

array<double, 3> gravitationForce(const Body &particle, const Body &source);
int qualifyBody(const Body &b, const array<double, 3> &center);


#endif