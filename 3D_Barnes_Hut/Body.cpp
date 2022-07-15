#include<array>
#include "Body.h"
#include<cmath>

using namespace std;


Body::Body(){
    mass = 0.0;
    position = array<double, 3> {0.0, 0.0, 0.0};
}

Body::Body(double *const arr){
    mass = arr[0];
    position = array<double, 3> {arr[1], arr[2], arr[3]};
}

Body::Body(const array<double, 4> &arr){
    mass = arr[0];
    position = array<double, 3> {arr[1], arr[2], arr[3]};
}

array<double, 3> gravitationForce(const Body &particle, const Body &source){
    double cubed_norm = pow( 
        sqrt(
            pow( (source.position[0]-particle.position[0]), 2.0 ) + \
            pow( (source.position[1]-particle.position[1]), 2.0 ) + \
            pow( (source.position[2]-particle.position[2]), 2.0 )
        ), 
        3.0
    );

    double masses = particle.mass * source.mass;
    
    return array<double, 3> {
        (source.position[0]-particle.position[0]) / cubed_norm * masses, 
        (source.position[1]-particle.position[1]) / cubed_norm * masses, 
        (source.position[2]-particle.position[2]) / cubed_norm * masses
        };
}

int qualifyBody(const Body &body, const array<double, 3> &center){
    int hash = 
        (int)( body.position[0] - center[0] > 0 ) * 2 + \
        (int)( body.position[1] - center[1] > 0 ) * 3 + \ 
        (int)( body.position[2] - center[2] > 0 ) * 7;

    switch(hash){
        case 0:
            break;

        case 2:
            break;
        
        case 3:
            break;

        case 7:
            break;

        case 5:
            break;

        case 9:
            break;

        case 10:
            break;

        case 12:
            break; 

        default:
            return -1;
            break;
    }
}