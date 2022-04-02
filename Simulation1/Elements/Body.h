#ifndef ELEMENTS_BODY_H
#define ELEMENTS_BODY_H

#include "Vector.h"
#include<list>
#include<vector>

class Body {
public:
    double mass;
    Vector position;

    Body();
    Body(const double &Mass, const Vector &Position);
    explicit Body(const std::vector<double> &params);
};

void stateToBody(const std::vector<std::vector<double>> &state, std::list<Body> &bodies, const int &count);


#endif //ELEMENTS_BODY_H
