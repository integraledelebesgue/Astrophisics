#include "Body.h"
#include<cmath>

using namespace std;


Body::Body(){
    mass = 0.0;
    position = Vector();
}

Body::Body(const array<double, 4> &params){
    mass = params[0];
    position = Vector{params[1], params[2], params[3]};
}

Body::Body(const double &_mass, const Vector &_position){
    mass = _mass;
    position = _position;
}

Vector Body::getPosition(){
    return position;
}

Body massCenter(const list<Body> &body_list){
    double total_mass = 0;
    Vector total_position;

    for(const Body &body : body_list){
        total_mass += body.mass;
        total_position += body.position;
    }

    return Body(total_mass, total_position / total_mass);
}

short int qualify(const Body &body, const Vector &center){
    // 0: + + +
    // 1: - + +
    // 2: + - +
    // 3: + + -
    // 4: + - -
    // 5: - + -
    // 6: - - + 
    // 7: - - -

    switch(segmentHash(body.position - center)){
        case 0:
            return 7;

        case 7:
            return 6;
        
        case 3:
            return 5;

        case 2:
            return 4;

        case 5:
            return 3;

        case 9:
            return 2;

        case 10:
            return 1;

        case 12:
            return 0;

        default:
            return -1;
    }
}

Vector graviForce(const Body &particle, const Body &source){
    Vector relative_position = source.position - particle.position;
    return particle.mass * source.mass * relative_position / pow(norm(relative_position), 3);
}

bool operator ==(const Body &b1, const Body &b2){
    return b1.mass == b2.mass && b1.position == b2.position;
}