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

    body pseudobody = {.mass = total_mass, .centre = centre};

    return pseudobody;
}

point compute_force(body particle, body source){
    /// Returns a force vector representing gravity affected on "particle" by "source.
    d = distance(particle.position, source.position);

    double scalar_force = 6.67*e-11*particle.mass*source.mass/(d*d);

    point force_vector = {.x = scalar_force*(source.position.x - particle.position.x)/d, .y = scalar_force*(source.position.y - particle.position.y)/d};

    return force_vector;
}

double distance(point a, point b){
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double **compute_forces(node *root, long length){
    point *forces = (point *)malloc(count*sizeof(point));

    for(long i = 0; i < length; i++){
        forces[i] = resultant_force(root, i); //TODO resultant force function
    }

    return point_to_array(forces, length); //TODO point to array function
}

point resultant_force(node *root, long i){
    point force;

}
