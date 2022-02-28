#include "headers.h"
#include<math.h>

body compute_mass_centre(int count, body *bodies){
    /// Computes the centre of mass for the body list given.
    point centre;
    double total_mass;
    for(int i = 0; i<count; i++){
        centre.x = bodies[i].mass*bodies[i].position.x;
        centre.y = bodies[i].mass*bodies[i].position.y;
        total_mass += bodies[i].mass;
    }

    centre.x /= total_mass;
    centre.y /= total_mass;

    return body pseudo_body(total_mass, centre);
}

point compute_force(body particle, body source){
    /// Returns a force vector representing gravity affected on b1 by b2.
    d = distance(particle.position, source.position);
    double scalar_force = 6.67*e-11*particle.mass*source.mass/(d*d);
    return point force = (scalar_force*(source.position.x - particle.position.x)/d, scalar_force*(source.position.y - particle.position.y)/d);
}

double distance(point a, point b){
    return double sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
