#ifndef ELEMENTS_BODY_H
#define ELEMENTS_BODY_H

#include "Vector.h"
#include<list>

class Body {
public:
    double mass;
    Vector position;

    Body();
    Body(const double &Mass, const Vector &Position);
    explicit Body(const double state[3]);
};

void stateToBody(double **state, std::list<Body> &bodies, const int &count);


#endif //ELEMENTS_BODY_H
