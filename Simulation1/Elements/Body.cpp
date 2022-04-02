#include "Body.h"
#include<list>
#include<vector>

Body::Body(){
    mass = 0.0;
    position = Vector();
}

Body::Body(const double &Mass, const Vector &Position){
    mass = Mass;
    position = Position;
}

Body::Body(const std::vector<double> &params){
    mass = params[0];
    position = Vector(params[1], params[2]);
}

void stateToBody(const std::vector<std::vector<double>> &state, std::list<Body> &bodies, const int &count){
    for(int i=0; i<count; i++)
        bodies.emplace_back(Body(state[i]));
}